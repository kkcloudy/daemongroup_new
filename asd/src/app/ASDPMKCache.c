/*******************************************************************************
Copyright (C) Autelan Technology


This software file is owned and distributed by Autelan Technology 
********************************************************************************


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************
* AsdPmksaCache.c
*
*
* CREATOR:
* autelan.software.WirelessControl. team
*
* DESCRIPTION:
* asd module
*
*
*******************************************************************************/

#include "includes.h"
#include "wcpss/waw.h"
#include "wcpss/wid/WID.h"
#include "common.h"
#include "include/auth.h"
#include "ap.h"
#include "config.h"
#include "common.h"
#include "circle.h"
#include "sha1.h"
#include "ASD8021XOp.h"
#include "ASDEapolSM.h"
#include "ASDPMKCache.h"
#include "ASDPMKSta.h"
#include "wcpss/asd/asd.h"


static const int pmksa_cache_max_entries = 1024;
static const int dot11RSNAConfigPMKLifetime = 43200;

struct rsn_pmksa_cache {
#define PMKID_HASH_SIZE 128
#define PMKID_HASH(pmkid) (unsigned int) ((pmkid)[0] & 0x7f)
	struct rsn_pmksa_cache_entry *pmkid[PMKID_HASH_SIZE];
	struct rsn_pmksa_cache_entry *pmksa;
	int pmksa_count;

	void (*free_cb)(struct rsn_pmksa_cache_entry *entry, void *ctx);
	void *ctx;
};


/**
 * rsn_pmkid - Calculate PMK identifier
 * @pmk: Pairwise master key
 * @pmk_len: Length of pmk in bytes
 * @aa: Authenticator address
 * @spa: Supplicant address
 *
 * IEEE Std 802.11i-2004 - 8.5.1.2 Pairwise key hierarchy
 * PMKID = HMAC-SHA1-128(PMK, "PMK Name" || AA || SPA)
 */
void rsn_pmkid(const u8 *pmk, size_t pmk_len, const u8 *aa, const u8 *spa,
	       u8 *pmkid)
{
	char *title = "PMK Name";
	const u8 *addr[3];
	const size_t len[3] = { 8, ETH_ALEN, ETH_ALEN };
	unsigned char hash[SHA1_MAC_LEN];

	addr[0] = (u8 *) title;
	addr[1] = aa;
	addr[2] = spa;

	hmac_sha1_vector(pmk, pmk_len, 3, addr, len, hash);
	os_memcpy(pmkid, hash, PMKID_LEN);
}


static void pmksa_cache_set_expiration(struct rsn_pmksa_cache *pmksa);


static void _pmksa_cache_free_entry(struct rsn_pmksa_cache_entry *entry)
{
	if (entry == NULL)
		return;
	os_free(entry->identity);
	os_free(entry->cui_identity);
	ieee802_1x_free_radius_class(&entry->radius_class);
	os_free(entry);
}


static void pmksa_cache_free_entry(struct rsn_pmksa_cache *pmksa,
				   struct rsn_pmksa_cache_entry *entry)
{
	struct rsn_pmksa_cache_entry *pos, *prev;

	if(pmksa == NULL)
	    return;
	pmksa->pmksa_count--;
	pmksa->free_cb(entry, pmksa->ctx);
	pos = pmksa->pmkid[PMKID_HASH(entry->pmkid)];
	prev = NULL;
	while (pos) {
		if (pos == entry) {
			if (prev != NULL) {
				prev->hnext = pos->hnext;
			} else {
				pmksa->pmkid[PMKID_HASH(entry->pmkid)] =
					pos->hnext;
			}
			break;
		}
		prev = pos;
		pos = pos->hnext;
	}

	pos = pmksa->pmksa;
	prev = NULL;
	while (pos) {
		if (pos == entry) {
			if (prev != NULL)
				prev->next = pos->next;
			else
				pmksa->pmksa = pos->next;
			break;
		}
		prev = pos;
		pos = pos->next;
	}
	_pmksa_cache_free_entry(entry);
}


static void pmksa_cache_expire(void *circle_ctx, void *timeout_ctx)
{
	struct rsn_pmksa_cache *pmksa = circle_ctx;
	struct os_time now;

    if(pmksa == NULL)
		return;
	os_get_time(&now);
	while (pmksa->pmksa && pmksa->pmksa->expiration <= now.sec) {
		struct rsn_pmksa_cache_entry *entry = pmksa->pmksa;
		pmksa->pmksa = entry->next;
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "RSN: expired PMKSA cache entry for "
			   MACSTR, MAC2STR(entry->spa));
		pmksa_cache_free_entry(pmksa, entry);
	}

	pmksa_cache_set_expiration(pmksa);
}


static void pmksa_cache_set_expiration(struct rsn_pmksa_cache *pmksa)
{
	int sec;
	struct os_time now;
	
    if(pmksa == NULL)
	    return;
	circle_cancel_timeout(pmksa_cache_expire, pmksa, NULL);
	if (pmksa->pmksa == NULL)
		return;
	os_get_time(&now);
	sec = pmksa->pmksa->expiration - now.sec;
	if (sec < 0)
		sec = 0;
	circle_register_timeout(sec + 1, 0, pmksa_cache_expire, pmksa, NULL);
}


static void pmksa_cache_from_eapol_data(struct rsn_pmksa_cache_entry *entry,
					struct eapol_state_machine *eapol)
{
	if (eapol == NULL)
		return;

	if (eapol->identity) {
		entry->identity = os_zalloc(eapol->identity_len);
		if (entry->identity) {
			entry->identity_len = eapol->identity_len;
			os_memcpy(entry->identity, eapol->identity,
				  eapol->identity_len);
		}
	}
    if(eapol->cuiAvailable&&eapol->cui_identity)
	{
		entry->cui_identity = os_zalloc(eapol->cui_len);
		if(entry->cui_identity){
			entry->cui_len = eapol->cui_len;
			os_memcpy(entry->cui_identity,eapol->cui_identity,eapol->cui_len);
		}
	}
	ieee802_1x_copy_radius_class(&entry->radius_class,
				     &eapol->radius_class);

	entry->eap_type_authsrv = eapol->eap_type_authsrv;
	entry->vlan_id = eapol->sta->vlan_id;
}


void pmksa_cache_to_eapol_data(struct rsn_pmksa_cache_entry *entry,
			       struct eapol_state_machine *eapol)
{
	if (entry == NULL || eapol == NULL)
		return;

	if (entry->identity) {
		os_free(eapol->identity);
		eapol->identity = os_zalloc(entry->identity_len);
		if (eapol->identity) {
			eapol->identity_len = entry->identity_len;
			os_memcpy(eapol->identity, entry->identity,
				  entry->identity_len);
		}
		wpa_hexdump_ascii(MSG_DEBUG, "STA identity from PMKSA",
				  eapol->identity, eapol->identity_len);
	}
    if(entry->cui_identity){
		os_free(eapol->cui_identity);
		eapol->cui_identity = os_zalloc(entry->cui_len);
		if(eapol->cui_identity){
			eapol->cui_len = entry->cui_len;
			os_memcpy(eapol->cui_identity,entry->cui_identity,entry->cui_len);
			eapol->cuiAvailable = TRUE;
		}
	}
	ieee802_1x_free_radius_class(&eapol->radius_class);
	ieee802_1x_copy_radius_class(&eapol->radius_class,
				     &entry->radius_class);
	if (eapol->radius_class.attr) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "Copied %lu Class attribute(s) from "
			   "PMKSA", (unsigned long) eapol->radius_class.count);
	}

	eapol->eap_type_authsrv = entry->eap_type_authsrv;
	eapol->sta->vlan_id = entry->vlan_id;
}


/**
 * pmksa_cache_add - Add a PMKSA cache entry
 * @pmksa: Pointer to PMKSA cache data from pmksa_cache_init()
 * @pmk: The new pairwise master key
 * @pmk_len: PMK length in bytes, usually PMK_LEN (32)
 * @aa: Authenticator address
 * @spa: Supplicant address
 * @session_timeout: Session timeout
 * @eapol: Pointer to EAPOL state machine data
 * Returns: Pointer to the added PMKSA cache entry or %NULL on error
 *
 * This function create a PMKSA entry for a new PMK and adds it to the PMKSA
 * cache. If an old entry is already in the cache for the same Supplicant,
 * this entry will be replaced with the new entry. PMKID will be calculated
 * based on the PMK.
 */
struct rsn_pmksa_cache_entry *
pmksa_cache_add(struct rsn_pmksa_cache *pmksa, const u8 *pmk, size_t pmk_len,
		const u8 *aa, const u8 *spa, int session_timeout,
		struct eapol_state_machine *eapol)
{
	struct rsn_pmksa_cache_entry *entry, *pos, *prev;
	struct os_time now;

	if(pmksa == NULL)
		return NULL;
	if (pmk_len > PMK_LEN)
		return NULL;

	entry = os_zalloc(sizeof(*entry));
	if (entry == NULL)
		return NULL;
	os_memcpy(entry->pmk, pmk, pmk_len);
	entry->pmk_len = pmk_len;
	rsn_pmkid(pmk, pmk_len, aa, spa, entry->pmkid);
	os_get_time(&now);
	entry->expiration = now.sec;
	if (session_timeout > 0)
		entry->expiration += session_timeout;
	else
		entry->expiration += dot11RSNAConfigPMKLifetime;
	entry->akmp = WPA_KEY_MGMT_IEEE8021X;
	os_memcpy(entry->spa, spa, ETH_ALEN);
	pmksa_cache_from_eapol_data(entry, eapol);

	/* Replace an old entry for the same STA (if found) with the new entry
	 */
	pos = pmksa_cache_get(pmksa, spa, NULL);
	if (pos)
		pmksa_cache_free_entry(pmksa, pos);

	if (pmksa->pmksa_count >= pmksa_cache_max_entries && pmksa->pmksa) {
		/* Remove the oldest entry to make room for the new entry */
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "RSN: removed the oldest PMKSA cache "
			   "entry (for " MACSTR ") to make room for new one",
			   MAC2STR(pmksa->pmksa->spa));
		pmksa_cache_free_entry(pmksa, pmksa->pmksa);
	}

	/* Add the new entry; order by expiration time */
	pos = pmksa->pmksa;
	prev = NULL;
	while (pos) {
		if (pos->expiration > entry->expiration)
			break;
		prev = pos;
		pos = pos->next;
	}
	if (prev == NULL) {
		entry->next = pmksa->pmksa;
		pmksa->pmksa = entry;
	} else {
		entry->next = prev->next;
		prev->next = entry;
	}
	entry->hnext = pmksa->pmkid[PMKID_HASH(entry->pmkid)];
	pmksa->pmkid[PMKID_HASH(entry->pmkid)] = entry;

	pmksa->pmksa_count++;
	asd_printf(ASD_DEFAULT,MSG_DEBUG, "RSN: added PMKSA cache entry for " MACSTR,
		   MAC2STR(entry->spa));
	wpa_hexdump(MSG_DEBUG, "RSN: added PMKID", entry->pmkid, PMKID_LEN);

	return entry;
}

/*****************************************************************************
 *	pmksa_cache_delete_from_hash
 * 
 *	remove from pmkid hash
 *
 *  INPUT:
 *		pmksa - RSN pmksa cache (hash buctets)
 *		entry - RSN pmksa cache entry (hash node)
 *  
 *  OUTPUT:
 * 	 NULL
 *
 *  RETURN:
 * 	  0 - find entry and remove
 * 	 -1 - no such pmk entry
 *
 ****************************************************************************/
int pmksa_cache_delete_from_hash(struct rsn_pmksa_cache *pmksa,
				   struct rsn_pmksa_cache_entry *entry)
{
	struct rsn_pmksa_cache_entry *pos = NULL, *prev = NULL;

	if ((!pmksa) || (!entry)) {
		return -1;
	}

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "RSN: delete PMKSA cache entry for " MACSTR,
		   MAC2STR(entry->spa));

	pos = pmksa->pmkid[PMKID_HASH(entry->pmkid)];
	prev = NULL;
	while (pos) {
		if (pos == entry) {
			if (NULL != prev) {
				prev->hnext = pos->hnext;
			} else {
				pmksa->pmkid[PMKID_HASH(entry->pmkid)] = pos->hnext;
			}
			return 0;
		}
		prev = pos;
		pos = pos->hnext;
	}

	return -1;
}


/*****************************************************************************
 *	pmksa_cache_insert_to_hash
 * 
 *	insert entry to pmkid hash
 *
 *  INPUT:
 *		pmksa - RSN pmksa cache (hash buctets)
 *		entry - RSN pmksa cache entry (hash node)
 *  
 *  OUTPUT:
 * 	 NULL
 *
 *  RETURN:
 * 	  0 - success
 * 	 -1 - failed
 *
 ****************************************************************************/
int pmksa_cache_insert_to_hash(struct rsn_pmksa_cache *pmksa,
				   struct rsn_pmksa_cache_entry *entry)
{
	if ((!pmksa) || (!entry)) {
		return -1;
	}

	entry->hnext = pmksa->pmkid[PMKID_HASH(entry->pmkid)];
	pmksa->pmkid[PMKID_HASH(entry->pmkid)] = entry;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "RSN: insert PMKSA cache entry for " MACSTR,
		   MAC2STR(entry->spa));

	return 0;
}


/**
 * pmksa_cache_deinit - Free all entries in PMKSA cache
 * @pmksa: Pointer to PMKSA cache data from pmksa_cache_init()
 */
void pmksa_cache_deinit(struct rsn_pmksa_cache *pmksa)
{
	struct rsn_pmksa_cache_entry *entry, *prev;
	int i;

	if (pmksa == NULL)
		return;

	entry = pmksa->pmksa;
	while (entry) {
		prev = entry;
		entry = entry->next;
		_pmksa_cache_free_entry(prev);
	}
	circle_cancel_timeout(pmksa_cache_expire, pmksa, NULL);
	for (i = 0; i < PMKID_HASH_SIZE; i++)
		pmksa->pmkid[i] = NULL;
	os_free(pmksa);
}


/**
 * pmksa_cache_get - Fetch a PMKSA cache entry
 * @pmksa: Pointer to PMKSA cache data from pmksa_cache_init()
 * @spa: Supplicant address or %NULL to match any
 * @pmkid: PMKID or %NULL to match any
 * Returns: Pointer to PMKSA cache entry or %NULL if no match was found
 */
struct rsn_pmksa_cache_entry * pmksa_cache_get(struct rsn_pmksa_cache *pmksa,
					       const u8 *spa, const u8 *pmkid)
{
	struct rsn_pmksa_cache_entry *entry;

    if(pmksa == NULL)    //xk debug
	    return NULL;
	if (pmkid)
		entry = pmksa->pmkid[PMKID_HASH(pmkid)];
	else
		entry = pmksa->pmksa;
	while (entry) {
		if ((spa == NULL ||
		     os_memcmp(entry->spa, spa, ETH_ALEN) == 0) &&
		    (pmkid == NULL ||
		     os_memcmp(entry->pmkid, pmkid, PMKID_LEN) == 0))
			return entry;
		entry = pmkid ? entry->hnext : entry->next;
	}
	return NULL;
}


/**
 * pmksa_cache_init - Initialize PMKSA cache
 * @free_cb: Callback function to be called when a PMKSA cache entry is freed
 * @ctx: Context pointer for free_cb function
 * Returns: Pointer to PMKSA cache data or %NULL on failure
 */
struct rsn_pmksa_cache *
pmksa_cache_init(void (*free_cb)(struct rsn_pmksa_cache_entry *entry,
				 void *ctx), void *ctx)
{
	struct rsn_pmksa_cache *pmksa;

	pmksa = os_zalloc(sizeof(*pmksa));
	if (pmksa) {
		pmksa->free_cb = free_cb;
		pmksa->ctx = ctx;
	}

	return pmksa;
}
