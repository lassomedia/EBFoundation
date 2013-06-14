#import <Foundation/Foundation.h>

@interface EBBlockValueTransformer : NSValueTransformer
+ (instancetype)newWithForwardBlock: (id (^)(id value))forwardBlock;
+ (instancetype)newWithForwardBlock: (id (^)(id value))forwardBlock reverseBlock: (id (^)(id value))reverseBlock;
@end