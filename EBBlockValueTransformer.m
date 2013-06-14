#import "EBBlockValueTransformer.h"
#import "EBAssert.h"

@interface EBBlockValueTransformerWithReverse : EBBlockValueTransformer
@end

@implementation EBBlockValueTransformerWithReverse
{
    @public
    id (^_reverseBlock)(id value);
}

- (id)reverseTransformedValue: (id)value
{
        EBAssertOrBail(_reverseBlock);
    return _reverseBlock(value);
}

+ (BOOL)allowsReverseTransformation
{
    return YES;
}

@end

@implementation EBBlockValueTransformer
{
    id (^_forwardBlock)(id value);
}

+ (instancetype)newWithForwardBlock: (id (^)(id value))forwardBlock
{
    return [self newWithForwardBlock: forwardBlock reverseBlock: nil];
}

+ (instancetype)newWithForwardBlock: (id (^)(id value))forwardBlock reverseBlock: (id (^)(id value))reverseBlock
{
        NSParameterAssert(forwardBlock);
    
    EBBlockValueTransformer *result = [(!reverseBlock ? [EBBlockValueTransformer class] : [EBBlockValueTransformerWithReverse class]) new];
    result->_forwardBlock = forwardBlock;
    
    if (reverseBlock)
        ((EBBlockValueTransformerWithReverse *)result)->_reverseBlock = reverseBlock;
    
    return result;
}

- (id)transformedValue: (id)value
{
        EBAssertOrBail(_forwardBlock);
    return _forwardBlock(value);
}

+ (BOOL)allowsReverseTransformation
{
    return NO;
}

@end