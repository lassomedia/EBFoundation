#import <stdint.h>

typedef uint64_t EBTime;

EBTime EBTimeCurrentTime(void);
uint64_t EBTimeElapsedNanoseconds(EBTime startTime, EBTime endTime);

double EBTimeElapsedSeconds(EBTime startTime, EBTime endTime);
double EBTimeElapsedSecondsSince(EBTime startTime);