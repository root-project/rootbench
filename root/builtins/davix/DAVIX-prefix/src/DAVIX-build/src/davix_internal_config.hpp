#ifndef CONFIG_H
#define CONFIG_H


// POSIX inclusion
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

// C++ C mapping
#include <cstring>
#include <climits>
#include <cerrno>


// define alib namespace
#undef A_LIB_NAMESPACE
#define A_LIB_NAMESPACE Davix


// buffer parameters
#define DAVIX_BUFFER_SIZE 2048
#define DAVIX_READ_BLOCK_SIZE 4096

// default task queue size
#define DAVIX_DEFAULT_TASKQUEUE_SIZE 100

// default connexion timeout for HTTP/Dav connexion
#define DAVIX_DEFAULT_CONN_TIMEOUT 30

// default timeout on operations for HTTP/Webdav
#define DAVIX_DEFAULT_OPS_TIMEOUT 0

// default retry number
const int default_retry_number= 3;

// c++11
#define HAVE_CXX011_FULL_SUPPORT 1
#define HAVE_CXX011_PARTIAL_SUPPORT 1
#define HAVE_ATOMIC 1

// tr1
/* #undef HAVE_TR1_SUPPORT */

// curl as default
/* #undef LIBCURL_BACKEND_BY_DEFAULT */

// default export
#undef DAVIX_EXPORT
#define DAVIX_EXPORT


// POSIX
// has unistd
#define HAVE_UNISTD_H 1
// has clock_gettime
#define HAVE_GETTIMEOFDAY 1

// openssl backend
#define HAVE_OPENSSL 1

// has locale
#define HAVE_LOCALE_H 1

// has strptime
#define HAVE_STRPTIME_H 1
#ifndef HAVE_STRPTIME_H
#	define strptime __strptime
#endif

/* #undef HAVE_STRLCPY_H */

// have gmtime_r
#define HAVE_GMTIME_R 1

// readdir max name size
#ifndef NAME_MAX
#define NAME_MAX 256
#endif

// termios
#define HAVE_TERMIOS_H 1

// getconsolemode
/* #undef HAVE_SETCONSOLEMODE */

//
// Win 32 mapper
#if( defined _WIN32 )|| ( defined __MINGW32__ )
// macros

#define __PLATFORM_WINDOWS__

// stat struct def
typedef short nlink_t;
typedef short gid_t;
typedef short uid_t;

#undef DAVIX_EXPORT
#if defined(libdavix_EXPORTS)
#define  DAVIX_EXPORT __declspec(dllexport)
#else
#define  DAVIX_EXPORT __declspec(dllimport)
#endif /* libdavix_EXPORTS */

// windows headers
#include <Windows.h>
#include <Winnls.h>
#endif /* end of win32*/

#endif // CONFIG_H
