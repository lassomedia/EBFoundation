EBFoundation is a framework that includes various generally-useful classes and utilities, described below.

## EBAssert

EBAssert contains various flavors of assertion macros that allow clients to print detailed assertion information (such as file name, line number, and asserted expression), handle assertion failures, and raise exceptions.

## EBObservation

EBObservation is an elegantly simple key-value observing (KVO) wrapper, which supports blocks and automatic de-registration of observers.

## EBSingleton

EBSingleton is an abstract class that implements singleton behavior. Subclasses implement their initialization by overriding `-initSingleton`, and clients retrieve the singleton instance via `-sharedInstance`.

## EBTime

EBTime contains a simple set of functions for measuring the difference between two instances in time, down to nanosecond resolution.

## EBUtilities

A set of generally-useful functions and macros.

## NSTimer+EBBlockTimer

An NSTimer category allowing a block to be executed instead of a method.

## Requirements

- Mac OS 10.8 or iOS 6. (Earlier platforms have not been tested.)

## Integration

1. Drag EBFoundation.xcodeproj into your project's file hierarchy.
2. In your target's "Build Phases" tab:
    * Add EBFoundation as a dependency ("Target Dependencies" section)
    * Link against libEBFoundation.a ("Link Binary With Libraries" section)
3. Add `#import <EBFoundation/EBFoundation.h>` to your source files.

## Credits

EBFoundation was created for [Lasso](http://las.so).

## License

EBFoundation is available under the MIT license; see the LICENSE file for more information.