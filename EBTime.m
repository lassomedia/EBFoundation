#import "EBTime.h"
#import <mach/mach_time.h>
#import <libkern/OSAtomic.h>
#import "EBAssert.h"
#import "EBUtilities.h"

EBTime EBTimeCurrentTime()
{
    return mach_absolute_time();
}

uint64_t EBTimeElapsedNanoseconds(EBTime startTime, EBTime endTime)
{
    /* Initialize kTimebaseInfo, thread-safely */
    static mach_timebase_info_t kTimebaseInfo = nil;
    if (!kTimebaseInfo)
    {
        mach_timebase_info_t newTimebaseInfo = malloc(sizeof(*newTimebaseInfo));
        kern_return_t timebaseInfoResult = mach_timebase_info(newTimebaseInfo);
            EBAssertOrRecover(timebaseInfoResult == KERN_SUCCESS, return 0);
        
        /* Atomically swap kTimebaseInfo with newTimebaseInfo. If the swap fails, then it's because some other thread has
           initialized kTimebaseInfo, so we need to free newTimebaseInfo.
           
           We need a barrier here so that the memory at 'newTimebaseInfo' is all settled across CPU caches, before other
           threads can see the new value for 'kTimebaseInfo'. */
        if (!OSAtomicCompareAndSwapPtrBarrier(nil, newTimebaseInfo, (void * volatile *)&kTimebaseInfo))
        {
            free(newTimebaseInfo),
            newTimebaseInfo = nil;
        }
    }
    
    /* Get our thread-local timebaseInfo */
    mach_timebase_info_t timebaseInfo = kTimebaseInfo;
    
    /* We need a barrier on the read-end of kTimebaseInfo, so that all stores to the kTimebaseInfo memory
       are complete before all loads after the barrier. (A "data dependency barrier".) */
    OSMemoryBarrier();
    
    return (endTime - startTime) * timebaseInfo->numer / timebaseInfo->denom;
}

double EBTimeElapsedSeconds(EBTime startTime, EBTime endTime)
{
    return (double)EBTimeElapsedNanoseconds(startTime, endTime) / 1e9;
}

double EBTimeElapsedSecondsSince(EBTime startTime)
{
    return EBTimeElapsedSeconds(startTime, EBTimeCurrentTime());
}