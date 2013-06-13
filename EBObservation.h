#import <Foundation/Foundation.h>

@interface EBObservation : NSObject

+ (EBObservation *)observeObject: (NSObject *)observee keyPath: (NSString *)keyPath
    options: (NSKeyValueObservingOptions)options handlerBlock: (void (^)(EBObservation *observation, NSDictionary *change))handlerBlock;

- (void)invalidate;

@end