
#ifndef VPSC_EXPORT_H
#define VPSC_EXPORT_H

#ifdef _WIN32
#  ifdef VPSC_STATIC_DEFINE
#    define VPSC_EXPORT
#   define VPSC_NO_EXPORT
#  else
#    ifndef VPSC_EXPORT
#      ifdef vpsc_EXPORTS
          /* We are building this library */
#        define VPSC_EXPORT __declspec(dllexport)
#      else
          /* We are using this library */
#        define VPSC_EXPORT __declspec(dllimport)
#      endif
#    endif

#    ifndef VPSC_NO_EXPORT
#      define VPSC_NO_EXPORT
#    endif
#  endif

#  ifndef VPSC_DEPRECATED
#    define VPSC_DEPRECATED __declspec(deprecated)
#  endif

#  ifndef VPSC_DEPRECATED_EXPORT
#    define VPSC_DEPRECATED_EXPORT VPSC_EXPORT VPSC_DEPRECATED
#  endif

#  ifndef VPSC_DEPRECATED_NO_EXPORT
#    define VPSC_DEPRECATED_NO_EXPORT VPSC_NO_EXPORT VPSC_DEPRECATED
# endif

#  if 0 /* DEFINE_NO_DEPRECATED */
#    ifndef VPSC_NO_DEPRECATED
#      define VPSC_NO_DEPRECATED
#    endif
# endif
#else
#  define VPSC_EXPORT
#  define VPSC_NO_EXPORT
#endif /* _WIN32 */


#endif /* VPSC_EXPORT_H */
