#import <Foundation/Foundation.h>
#import <TargetConditionals.h>

#define EBTargetOSX (TARGET_OS_MAC && !TARGET_OS_IPHONE)
#define EBTargetIOS (TARGET_OS_MAC && TARGET_OS_IPHONE)

#define EBTry EBTry
#define EBFail EBFail
#define EBFinish EBFinish

#define EBStringify(a) #a
#define EBStringConstExtern(constantName) extern NSString *const constantName;
#define EBStringConst(constantName) NSString *const constantName = @EBStringify(constantName)
#define EBUniquePointerConst(constantName) const void *const constantName = (const void *const)&constantName
#define EBStaticArrayCount(array) (sizeof(array) / sizeof(*array))
#define EBEqualBools(a, b) ((bool)(a) == (bool)(b))
#define EBRaise(message, ...) [NSException raise: NSGenericException format: (message), ##__VA_ARGS__]

#define EBConfirmOrPerform(condition, action)      \
({                                                 \
    if (!(condition))                              \
    {                                              \
        action;                                    \
    }                                              \
})
#define EBNoOp (void)0

#define EBValueOrFallback(value, fallback)             \
({                                                     \
    __typeof__(value) __value = (value);               \
    __value ? __value : (fallback);                    \
})

#define EBMin(a, b)               \
({                                \
    __typeof__(a) __a = (a);      \
    __typeof__(b) __b = (b);      \
    __a < __b ? __a : __b;        \
})

#define EBMax(a, b)               \
({                                \
    __typeof__(a) __a = (a);      \
    __typeof__(b) __b = (b);      \
    __a < __b ? __b : __a;        \
})

#define EBCapMin EBMax
#define EBCapMax EBMin

#define EBCapRange(min, max, value)                                         \
({                                                                          \
    __typeof__(min) __min = (min);                                          \
    __typeof__(max) __max = (max);                                          \
    __typeof__(value) __value = (value);                                    \
    __value <= __min ? __min : (__value >= __max ? __max : __value);        \
})

#define EBValueInRange(min, max, value)         \
({                                              \
    __typeof__(min) __min = (min);              \
    __typeof__(max) __max = (max);              \
    __typeof__(value) __value = (value);        \
    __value >= __min && __value <=  __max;      \
})

#define EBValueInRangeExclusive(min, max, value)      \
({                                                    \
    __typeof__(min) __min = (min);                    \
    __typeof__(max) __max = (max);                    \
    __typeof__(value) __value = (value);              \
    __value >= __min && __value <  __max;             \
})

#if __has_feature(objc_arc)

    #define EBSetTimer(oldTimer, newTimer)                 \
    ({                                                     \
        __typeof__(oldTimer) __oldTimer = (oldTimer);      \
        NSTimer *__newTimer = (newTimer);                  \
                                                           \
        if (*__oldTimer != __newTimer)                     \
        {                                                  \
            [*__oldTimer invalidate];                      \
            *__oldTimer = __newTimer;                      \
        }                                                  \
    })

#else

    #define EBSetTimer(oldTimer, newTimer)                 \
    ({                                                     \
        __typeof__(oldTimer) __oldTimer = (oldTimer);      \
        NSTimer *__newTimer = (newTimer);                  \
                                                           \
        if (*__oldTimer != __newTimer)                     \
        {                                                  \
            [__newTimer retain];                           \
            [*__oldTimer invalidate];                      \
            [*__oldTimer release];                         \
            *__oldTimer = __newTimer;                      \
        }                                                  \
    })

#endif