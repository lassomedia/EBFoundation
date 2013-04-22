#import <Foundation/Foundation.h>

@interface EBSingleton : NSObject
/* ### EBSingleton subclasses must not override -init! Instead, you should override -initSingleton to perform initialization. */
/* +sharedInstanceForClass: is provided to allow non-EBSingleton-derived classes to implement singleton-like behavior. */
+ (instancetype)sharedInstance;
+ (instancetype)sharedInstanceForClass: (Class)cls;
- (void)initSingleton;
@end