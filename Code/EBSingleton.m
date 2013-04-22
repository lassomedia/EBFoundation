#import "EBSingleton.h"
#import "EBAssert.h"
#import "EBUtilities.h"

@implementation EBSingleton
static NSMutableDictionary *gEntries = nil;

#pragma mark - Creation -
+ (void)initialize
{
    static dispatch_once_t initToken;
    dispatch_once(&initToken,
    ^{
        gEntries = [NSMutableDictionary new];
    });
}

+ (instancetype)sharedInstance
{
    return [self sharedInstanceForClass: self];
}

+ (instancetype)sharedInstanceForClass: (Class)cls
{
    @synchronized(gEntries)
    {
        id result = [gEntries objectForKey: (id)cls];
        
        if (!result)
        {
            result = [[cls alloc] initWithCallToSuper: YES];
                EBAssertOrRecover(result, return nil);
            
            /* We set the entry in our map *before* we callout to -initSingleton, so that attempts to acquire the shared
               instance of 'cls' within -initSingleton return a value. */
            [gEntries setObject: result forKey: (id)cls];
            [result initSingleton];
        }
        
        return result;
    }
}

- (instancetype)init
{
        /* Verify that -init hasn't been overridden by a subclass (EBSingleton subclasses must use -initSingleton.) */
        EBAssertOrBail([EBSingleton instanceMethodForSelector: @selector(init)] == [[self class] instanceMethodForSelector: @selector(init)]);
    
    return [self initWithCallToSuper: NO];
}

- (instancetype)initWithCallToSuper: (BOOL)callToSuper
{
    if (callToSuper)
        return [super init];
    
    else
        return [[self class] sharedInstance];
}

- (void)initSingleton
{
}

@end