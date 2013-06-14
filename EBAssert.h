#import <Foundation/Foundation.h>
#import <EBFoundation/EBUtilities.h>

#define EBAssertOrRecover(condition, recoveryAction)                                                                                                                                  \
({                                                                                                                                                                                    \
    if (!(condition))                                                                                                                                                                 \
    {                                                                                                                                                                                 \
        EBAssertHandle(__FILE__, (uintmax_t)__LINE__, __PRETTY_FUNCTION__, EBStringify(condition), nil, NO);                                                                          \
        recoveryAction;                                                                                                                                                               \
    }                                                                                                                                                                                 \
})

#define EBAssertOrBailWithNote(condition, note, ...)                                                                                                                                            \
({                                                                                                                                                                                              \
    if (!(condition))                                                                                                                                                                           \
        EBAssertHandle(__FILE__, (uintmax_t)__LINE__, __PRETTY_FUNCTION__, EBStringify(condition), [[NSString stringWithFormat: (note), ##__VA_ARGS__] UTF8String], YES);                       \
})

#define EBAssertOrBail(condition)                                                                                                                                                               \
({                                                                                                                                                                                              \
    if (!(condition))                                                                                                                                                                           \
        EBAssertHandle(__FILE__, (uintmax_t)__LINE__, __PRETTY_FUNCTION__, EBStringify(condition), nil, YES);                                                                                   \
})

#define EBAssertLog(note, ...)                                                                                                                                                                  \
({                                                                                                                                                                                              \
    EBAssertHandle(__FILE__, (uintmax_t)__LINE__, __PRETTY_FUNCTION__, nil, [[NSString stringWithFormat: (note), ##__VA_ARGS__] UTF8String], NO);                                               \
})

void EBAssertHandle(const char *file, uintmax_t line, const char *function, const char *assertion, const char *note, BOOL raiseException);