#import "EBUtilities.h"

void EBSetTimer(NSTimer **oldTimer, NSTimer *newTimer)
{
        NSCParameterAssert(oldTimer);
    
    if (*oldTimer != newTimer)
    {
        [*oldTimer invalidate];
        *oldTimer = newTimer;
    }
}