#ifndef _DHCP_SNP_NETLINK_H_
#define _DHCP_SNP_NETLINK_H_

/* dhcp snooping rtnetlink handle */
struct dhcp_rtnl_handle {
	int fd;
};

/* dhcp snooping netlink ip neigh operator */
enum dhcpsnp_rtnl_ipneigh_op {
	DHCPSNP_RTNL_IPNEIGH_ADD_E,
	DHCPSNP_RTNL_IPNEIGH_DEL_E,
	DHCPSNP_RTNL_IPNEIGH_UPDATE_E
};

/* dhcp snooping netlink add route operator */
enum dhcpsnp_rtnl_static_route_op {
	DHCPSNP_RTNL_STATIC_ROUTE_ADD_E,
	DHCPSNP_RTNL_STATIC_ROUTE_DEL_E,
	DHCPSNP_RTNL_STATIC_ROUTE_UPDATE_E
};

/* dhcp snooping netlink ip neigh description */
#define DCHPSNP_RTNL_IPNEIGH_DESC(op) \
	(DHCPSNP_RTNL_IPNEIGH_ADD_E == op) ? "add": \
	(DHCPSNP_RTNL_IPNEIGH_DEL_E == op) ? "del": \
	(DHCPSNP_RTNL_IPNEIGH_UPDATE_E == op) ? "update": "unkown"
/* dhcp snooping netlink add host route description */
#define DCHPSNP_RTNL_ADD_STATIC_ROUTE_DESC(op) \
	(DHCPSNP_RTNL_STATIC_ROUTE_ADD_E == op) ? "add": \
	(DHCPSNP_RTNL_STATIC_ROUTE_DEL_E == op) ? "del": \
	(DHCPSNP_RTNL_STATIC_ROUTE_UPDATE_E == op) ? "update": "unkown"

/* ip neigh command */
#define DHCPSNP_RTNL_CMD_IPNEIGH_ADD	RTM_NEWNEIGH
#define DHCPSNP_RTNL_CMD_IPNEIGH_DEL	RTM_DELNEIGH

/* ip neigh flag */
#define RTNL_IPNEIGH_ADD_FLAGS	\
	(NLM_F_CREATE|NLM_F_REPLACE|NLM_F_REQUEST)
#define RTNL_IPNEIGH_DEL_FLAGS	\
	(NLM_F_REQUEST)

/* ip neigh family type */
#define DHCPSNP_RTNL_IPNEIGH_FAMILY		AF_INET

#define FD_INVALID(fd) (fd < 0)

#define NLMSG_TAIL(nmsg) \
	((struct rtattr *) (((void *) (nmsg)) + NLMSG_ALIGN((nmsg)->nlmsg_len)))

#define DHCPSNP_NL_TRUE		1
#define DHCPSNP_NL_FALSE	0

extern int dhcpsnp_ipneigh_on;

/**********************************************************************************
 * dhcp_snp_netlink_init
 *	Initialize DHCP snooping netlink socket
 *
 *	INPUT:
 *		NULL
 *
 *	OUTPUT:
 *		NULL
 *
 *	RETURN:
 *		DHCP_SNP_RETURN_CODE_OK		- success
 *	 	DHCP_SNP_RETURN_CODE_ERROR		- fail
 **********************************************************************************/
int dhcp_snp_netlink_init(void);

/**********************************************************************************
 * dhcp_snp_netlink_init
 *	Initialize DHCP snooping netlink socket
 *
 *	INPUT:
 *		NULL
 *
 *	OUTPUT:
 *		NULL
 *
 *	RETURN:
 *		DHCP_SNP_RETURN_CODE_OK		- success
 *	 	DHCP_SNP_RETURN_CODE_ERROR		- fail
 **********************************************************************************/
int dhcp_snp_netlink_do_ipneigh
(
	enum dhcpsnp_rtnl_ipneigh_op cmd,
	unsigned int ifindex,
	unsigned int ipaddr,
	unsigned char *mac
);

/**********************************************************************************
 * dhcp_snp_netlink_ipneigh_ctrl
 *	Control DHCP snooping ip neigh operation
 *
 *	INPUT:
 *		NULL
 *
 *	OUTPUT:
 *		NULL
 *
 *	RETURN:
 *		DHCP_SNP_RETURN_CODE_OK		- success
 **********************************************************************************/
int dhcp_snp_netlink_ipneigh_ctrl
(
	unsigned char enable
);
#define NLM_F_EXCL	0x200	/* Do not touch, if it exists	*/
#define NLM_F_CREATE	0x400	/* Create, if it does not exist	*/
#define RTM_DELROUTE   25
#define RTM_NEWROUTE   24
#define RTPROT_BOOT	3	/* Route installed during boot		*/
#define RT_SCOPE_UNIVERSE 0
#define RTN_UNICAST    1
#define RT_SCOPE_NOWHERE 255
#define RT_SCOPE_LINK  253
#endif
