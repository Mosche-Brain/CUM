#ifndef CUM_C_EXPORT_H
#define CUM_C_EXPORT_H

/* Symbol visibility of the C binding.
 *  - CUM_C_BUILDING     is defined while the shared library itself is compiled,
 *  - CUM_C_STATIC_DEFINE is defined when the binding is built or consumed as a static library. */
#if defined(CUM_C_STATIC_DEFINE)
    #define CUM_C_API
#elif defined(_WIN32) || defined(__CYGWIN__)
    #if defined(CUM_C_BUILDING)
        #define CUM_C_API __declspec(dllexport)
    #else
        #define CUM_C_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) || defined(__clang__)
    #define CUM_C_API __attribute__((visibility("default")))
#else
    #define CUM_C_API
#endif

#endif /* CUM_C_EXPORT_H */
