#ifndef CONFIG_H
#define CONFIG_H

// portability mapper
#include <limits.h>

// force debug support
#define NE_DEBUGGING

// force dav
#define NE_HAVE_DAV 1

// Force TLS and thread safety callback once forever
#define HAVE_CRYPTO_SET_IDPTR_CALLBACK
#define NE_HAVE_TS_SSL

//has malloc
/* #undef HAVE_MALLOC_H */

// has errno
#define HAVE_ERRNO_H 1

// has stdlib
#define HAVE_STDLIB_H 1

// has fcntl
#define HAVE_FCNTL_H 1

// string and strings
#define  HAVE_STRING_H 1
#define  HAVE_STRINGS_H 1

// has unistd
#define HAVE_UNISTD_H 1

// has I18N
/* #undef NE_HAVE_I18N */

// ipv6 support
/* #undef HAVE_IPV6 */

// tcp no delay
#define TCP_NODELAY 1

// has system select
#define HAVE_SYS_SELECT_H 1

// has system socket
#define HAVE_SYS_SOCKET_H 1

// has system time
#define HAVE_SYS_TIME_H 1

// has system uio
#define HAVE_SYS_UIO_H 1

// has setsockopt
#define HAVE_SETSOCKOPT 1

// has signal support
#define HAVE_SIGNAL_H 1

#ifdef HAVE_SIGNAL_H
#define HAVE_SIGNAL
#endif

// has getaddrinfo
#define HAVE_GETADDRINFO_H 1
#ifdef HAVE_GETADDRINFO_H
#define USE_GETADDRINFO 1
#endif

// has locale
#define HAVE_LOCALE_H 1

// general SSL support
#define NE_HAVE_SSL 1

// openssl support
#define HAVE_OPENSSL 1

//gnutls support
/* #undef HAVE_GNUTLS */

// libxml support
#define HAVE_LIBXML 1

// libexpat support
/* #undef HAVE_EXPAT */

// has strptime
#define HAVE_STRPTIME_H 1
#ifndef HAVE_STRPTIME_H
#	define strptime __strptime
#endif

// has mempcpy
/* #undef HAVE_MEMPCPY_H */
//#include <mempcpy/mempcpy.h>

/* #undef HAVE_STRLCPY_H */

// poll
#define HAVE_SYS_POLL_H 1
#ifdef HAVE_SYS_POLL_H
#define NE_USE_POLL
#endif

//net
#define HAVE_NETINET_IN_H 1
#define HAVE_NETINET_TCP_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_NETDB_H 1

// in_add_t
#define HAVE_IN_ADDR_T 1
#ifndef HAVE_IN_ADDR_T
#define in_addr_t unsigned int
#endif

// socklen_t
#define HAVE_SOCKLEN_T 1
#ifndef HAVE_SOCKLEN_T
#define socklen_t int
#endif

// type size
#define SIZEOF_INT 4
#define SIZEOF_LONG 8
#define SIZEOF_SIZE_T 8
#define SIZEOF_SSIZE_T 8
#define SIZEOF_OFF_T 8

#if( SIZEOF_INT == SIZEOF_SIZE_T )
#   define NE_FMT_SIZE_T "d"
#else
#   define NE_FMT_SIZE_T "ld"
#endif

#if( SIZEOF_INT == SIZEOF_SSIZE_T )
#   define NE_FMT_SSIZE_T "d"
#else
#   define NE_FMT_SSIZE_T "ld"
#endif

#if( SIZEOF_INT == SIZEOF_OFF_T )
#   define NE_FMT_OFF_T "d"
#else
#   define NE_FMT_OFF_T "ld"
#endif


//
// Win 32 mapper
#if( defined _WIN32 )|| ( defined __MINGW32__ )
// macros

#define __PLATFORM_WINDOWS__

// windows headers
#include <Windows.h>
#include <Winnls.h>
#endif /* end of win32*/



#endif // CONFIG_H
