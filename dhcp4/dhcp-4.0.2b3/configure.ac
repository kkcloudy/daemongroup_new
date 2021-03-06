AC_INIT([DHCP], [4.0.2b3], [dhcp-users@isc.org])

# we specify "foreign" to avoid having to have the GNU mandated files,
# like AUTHORS, COPYING, and such
AM_INIT_AUTOMAKE([foreign])

# We want to turn on warnings if we are using gcc and the user did 
# not specify CFLAGS. The autoconf check for the C compiler sets the
# CFLAGS if gcc is used, so we will save it before we run that check.
SAVE_CFLAGS="$CFLAGS"

# Now find our C compiler.
AC_PROG_CC

# Suppress warnings about --datarootdir
AC_DEFUN([AC_DATAROOTDIR_CHECKED])

# If we have gcc, and AC_PROG_CC changed the flags, then we know the
# user did not specify any flags. Add warnings in this case.
if test "$GCC" = "yes"; then
	if test "$CFLAGS" != "$SAVE_CFLAGS"; then
		STD_CWARNINGS="$STD_CWARNINGS -Wall -Werror -fno-strict-aliasing"
	fi
fi

# POSIX doesn't include the IPv6 Advanced Socket API and glibc hides
# parts of the IPv6 Advanced Socket API as a result.  This is stupid
# as it breaks how the two halves (Basic and Advanced) of the IPv6
# Socket API were designed to be used but we have to live with it.
# Use this to define _GNU_SOURCE to pull in the IPv6 Advanced Socket API.
AC_USE_SYSTEM_EXTENSIONS

AC_PROG_RANLIB
AC_CONFIG_HEADERS([includes/config.h])

# we sometimes need to know byte order for building packets
AC_C_BIGENDIAN(AC_SUBST(byte_order, BIG_ENDIAN), 
	       AC_SUBST(byte_order, LITTLE_ENDIAN))
AC_DEFINE_UNQUOTED([DHCP_BYTE_ORDER], [$byte_order], 
		   [Define to BIG_ENDIAN for MSB (Motorola or SPARC CPUs)
		    or LITTLE_ENDIAN for LSB (Intel CPUs).])

# DHCPv6 is off by default
AC_ARG_ENABLE(dhcpv6,
	AC_HELP_STRING([--enable-dhcpv6],
		       [enable support for DHCPv6 (default is yes)]))
if test "$enable_dhcpv6" != "no"; then
	AC_DEFINE([DHCPv6], [1], 
		  [Define to 1 to include DHCPv6 support.])
fi

###
### Path fun.  Older versions of DHCP were installed in /usr/sbin, so we
### need to look there and potentially overwrite by default (but not if
### the user configures an alternate value).  LOCALSTATEDIR is totally
### braindead.  No one uses /usr/local/var/db/ nor /usr/local/var/run, and
### they would be insane for suggesting it.  We need to look in /var/for
### 'db' and 'state/dhcp' for db files, and /var/run for pid files by
### default.
###
AC_PREFIX_PROGRAM(dhcpd)

# XXX - isn't there SOME WAY to default autoconf to /var instead of
# /usr/local/var/no/one/has/this/please/stop/trying?
case "$localstatedir" in
	'${prefix}/var')
		localstatedir=/var
		;;
esac

# Allow specification of alternate state files
AC_ARG_WITH(srv-lease-file,
	AC_HELP_STRING([--with-srv-lease-file=PATH],
		       [File for dhcpd leases 
		        (default is LOCALSTATEDIR/db/dhcpd.leases)]),
	AC_DEFINE_UNQUOTED([_PATH_DHCPD_DB], ["$withval"],
			   [File for dhcpd leases.]))

echo -n "checking for dhcpd.leases location..."
if [[ "x$with_srv_lease_file" = "x" ]] ; then
	if [[ -d "${localstatedir}/db" ]] ; then
		with_srv_lease_file="${localstatedir}/db/dhcpd.leases"
	elif [[ -d "${localstatedir}/state" ]] ; then
		if [[ -d "${localstatedir}/state/dhcp" ]] ; then
			with_srv_lease_file="${localstatedir}/state/dhcp/dhcpd.leases"
		else
			with_srv_lease_file="${localstatedir}/state/dhcpd.leases"
		fi
	elif [[ -d "${localstatedir}/lib" ]] ; then
		if [[ -d "${localstatedir}/lib/dhcp" ]] ; then
			with_srv_lease_file="${localstatedir}/lib/dhcp/dhcpd.leases"
		else
			with_srv_lease_file="${localstatedir}/lib/dhcpd.leases"
		fi
	elif [[ -d "${localstatedir}/etc" ]] ; then
		with_srv_lease_file="${localstatedir}/etc/dhcpd.leases"
	else
		with_srv_lease_file="/etc/dhcpd.leases"
	fi
fi
echo "$with_srv_lease_file"

AC_ARG_WITH(cli-lease-file,
	AC_HELP_STRING([--with-cli-lease-file=PATH],
		       [File for dhclient leases 
		        (default is LOCALSTATEDIR/db/dhclient.leases)]),
	AC_DEFINE_UNQUOTED([_PATH_DHCLIENT_DB], ["$withval"],
			   [File for dhclient leases.]))

echo -n "checking for dhclient.leases location..."
if [[ "x$with_cli_lease_file" = "x" ]] ; then
	if [[ -d "${localstatedir}/db" ]] ; then
		with_cli_lease_file="${localstatedir}/db/dhclient.leases"
	elif [[ -d "${localstatedir}/state" ]] ; then
		if [[ -d "${localstatedir}/state/dhcp" ]] ; then
			with_cli_lease_file="${localstatedir}/state/dhcp/dhclient.leases"
		else
			with_cli_lease_file="${localstatedir}/state/dhclient.leases"
		fi
	elif [[ -d "${localstatedir}/lib" ]] ; then
		if [[ -d "${localstatedir}/lib/dhcp" ]] ; then
			with_cli_lease_file="${localstatedir}/lib/dhcp/dhclient.leases"
		else
			with_cli_lease_file="${localstatedir}/lib/dhclient.leases"
		fi
	elif [[ -d "${localstatedir}/etc" ]] ; then
		with_cli_lease_file="${localstatedir}/etc/dhclient.leases"
	else
		with_cli_lease_file="/etc/dhclient.leases"
	fi
fi
echo "$with_cli_lease_file"

AC_ARG_WITH(srv-pid-file,
	AC_HELP_STRING([--with-srv-pid-file=PATH],
		       [File for dhcpd process information
		        (default is LOCALSTATEDIR/run/dhcpd.pid)]),
	AC_DEFINE_UNQUOTED([_PATH_DHCPD_PID], ["$withval"],
			   [File for dhcpd process information.]))
AC_ARG_WITH(cli-pid-file,
	AC_HELP_STRING([--with-cli-pid-file=PATH],
		       [File for dhclient process information
		        (default is LOCALSTATEDIR/run/dhclient.pid)]),
	AC_DEFINE_UNQUOTED([_PATH_DHCLIENT], ["$withval"],
			   [File for dhclient process information.]))
AC_ARG_WITH(relay-pid-file,
	AC_HELP_STRING([--with-relay-pid-file=PATH],
		       [File for dhcrelay process information
		        (default is LOCALSTATEDIR/run/dhcrelay.pid)]),
	AC_DEFINE_UNQUOTED([_PATH_DHCRELAY_PID], ["$withval"],
			   [File for dhcrelay process information.]))

# Check basic types.
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T

# Some systems need the u_intX_t types defined across.
AC_CHECK_TYPE([u_int8_t], [], [
  AC_TYPE_UINT8_T
  AC_DEFINE(u_int8_t, [uint8_t], [Define a type for 8-bit unsigned
				  integers.])
])
AC_CHECK_TYPE([u_int16_t], [], [
  AC_TYPE_UINT16_T
  AC_DEFINE(u_int16_t, [uint16_t], [Define a type for 16-bit unsigned
				    integers.])
])
AC_CHECK_TYPE([u_int32_t], [], [
  AC_TYPE_UINT32_T
  AC_DEFINE(u_int32_t, [uint32_t], [Define a type for 32-bit unsigned
				    integers.])
])

# see if ifaddrs.h is available
AC_CHECK_HEADERS(ifaddrs.h)

# figure out what IPv4 interface code to use
AC_CHECK_HEADERS(linux/types.h)  # needed for linux/filter.h on old systems

AC_CHECK_HEADER(linux/filter.h, DO_LPF=1, ,
[
#ifdef HAVE_LINUX_TYPES_H
#include <linux/types.h>
#endif
])
if test -n "$DO_LPF"
then
	AC_DEFINE([HAVE_LPF], [1], 
		  [Define to 1 to use the Linux Packet Filter interface code.])
else
	AC_CHECK_HEADER(sys/dlpi.h, DO_DLPI=1)
	if test -n "$DO_DLPI"
	then
		AC_DEFINE([HAVE_DLPI], [1], 
			  [Define to 1 to use DLPI interface code.])
	else
		AC_CHECK_HEADER(net/bpf.h, DO_BPF=1)
		if test -n "$DO_BPF"
		then
			AC_DEFINE([HAVE_BPF], [""],
	  			  [Define to 1 to use the 
				   Berkeley Packet Filter interface code.])
		fi
	fi
fi

# SIOCGLIFCONF uses some transport structures.  Trick is not all platforms
# use the same structures.  We like to use 'struct lifconf' and 'struct
# lifreq', but we'll use these other structures if they're present.  HPUX
# does not define 'struct lifnum', but does use SIOCGLIFNUM - they use an
# int value.
#
AC_MSG_CHECKING([for struct lifnum])
AC_TRY_COMPILE(
[ #include <sys/types.h>
  #include <sys/socket.h>
  #include <net/if.h>
],
[ struct lifnum a;
],
	[AC_MSG_RESULT(yes)
	 AC_DEFINE([ISC_PLATFORM_HAVELIFNUM], [1],
		   [Define to 1 if the system has 'struct lifnum'.])],
	[AC_MSG_RESULT(no)])

AC_MSG_CHECKING([for struct if_laddrconf])
AC_TRY_COMPILE(
[ #include <sys/types.h>
  #include <net/if6.h>
],
[ struct if_laddrconf a;
],
	[AC_MSG_RESULT(yes)
	 AC_DEFINE([ISC_PLATFORM_HAVEIF_LADDRCONF], [1],
		   [Define to 1 if the system has 'struct if_laddrconf'.])],
	[AC_MSG_RESULT(no)])

AC_MSG_CHECKING([for struct if_laddrreq])
AC_TRY_LINK(
[#include <sys/types.h>
 #include <net/if6.h>
],
[ struct if_laddrreq a;
],
	[AC_MSG_RESULT(yes)
	 AC_DEFINE([ISC_PLATFORM_HAVEIF_LADDRREQ], [1],
		   [Define to 1 if the system has 'struct if_laddrreq'.])],
	[AC_MSG_RESULT(no)])

# Look for optional headers.
AC_CHECK_HEADERS(sys/socket.h net/if_dl.h net/if6.h regex.h)

# find an MD5 library
AC_SEARCH_LIBS(MD5_Init, [crypto])
AC_SEARCH_LIBS(MD5Init, [crypto])

# Solaris needs some libraries for functions
AC_SEARCH_LIBS(socket, [socket])
AC_SEARCH_LIBS(inet_ntoa, [nsl])

AC_SEARCH_LIBS(inet_aton, [socket nsl], , 
	AC_DEFINE([NEED_INET_ATON], [1], 
		  [Define to 1 if the inet_aton() function is missing.]))

# Check for a standalone regex library.
AC_SEARCH_LIBS(regcomp, [regex])

# For HP/UX we need -lipv6 for if_nametoindex, perhaps others.
AC_SEARCH_LIBS(if_nametoindex, [ipv6])

# check for /dev/random (declares HAVE_DEV_RANDOM)
AC_CHECK_FILE(/dev/random,
	AC_DEFINE([HAVE_DEV_RANDOM], [1], 
		  [Define to 1 if you have the /dev/random file.]))

# see if there is a "sa_len" field in our interface information structure
AC_CHECK_MEMBER(struct sockaddr.sa_len,
	AC_DEFINE([HAVE_SA_LEN], [], 
		  [Define to 1 if the sockaddr structure has a length field.]),
	,
	[#include <sys/socket.h>])

# figure out pointer size
AC_CHECK_SIZEOF(struct iaddr *, , [
#include "includes/inet.h"
#include <stdio.h>
])

# Solaris does not have the msg_control or msg_controlen members in 
# in the msghdr structure unless you define:
#
#   _XOPEN_SOURCE, _XOPEN_SOURCE_EXTENDED, and __EXTENSIONS__
# 
# See the "standards" man page for details.
# 
# We check for the msg_control member, and if it is not found, we check
# again with the appropriate defines added to the CFLAGS. (In order to
# do this we have to remove the check from the cache, which is what the
# "unset" is for.)
AC_CHECK_MEMBER(struct msghdr.msg_control,,
	[CFLAGS="$CFLAGS -D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1"
	 CFLAGS="$CFLAGS -D__EXTENSIONS__"
	 unset ac_cv_member_struct_msghdr_msg_control
	 AC_CHECK_MEMBER(struct msghdr.msg_control,,
	 	[AC_MSG_ERROR([Missing msg_control member in 
			       msg_control structure.])],
		[
#include <sys/types.h>
#include <sys/socket.h>
		])
	],
	[
#include <sys/types.h>
#include <sys/socket.h>
	])

# Append selected warning levels to CFLAGS before substitution (but after
# AC_TRY_COMPILE & etc).
CFLAGS="$CFLAGS $STD_CWARNINGS"

AC_OUTPUT([
  Makefile
  client/Makefile
  common/Makefile
  common/tests/Makefile
  dhcpctl/Makefile
  dst/Makefile
  includes/Makefile
  minires/Makefile
  omapip/Makefile
  relay/Makefile
  server/Makefile
  tests/Makefile
])

