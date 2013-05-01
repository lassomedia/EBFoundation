This repository includes various generally-useful classes and utilities, described below.

## EBAssert

EBAssert contains various flavors of assertion macros that allow clients to print detailed assertion information (such as file name, line number, and asserted expression), handle assertion failures, and raise exceptions.

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
- Automatic reference counting (ARC) must be enabled for the source files.

## Integration

1. Drag the EBFoundation Xcode project into your project hierarchy
2. Add the appropriate dependency from the EBFoundation project: EBFoundation-osx for OS X, or EBFoundation-ios for iOS
3. Link against libEBFoundation