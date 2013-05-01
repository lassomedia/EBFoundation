This repository includes various generally-useful classes and utilities, described below.

## EBAssert

EBAssert contains various flavors of assertion macros that allow clients to print detailed assertion information (such as file name, line number, and the asserted expression), handle assertion failures, and raise exceptions.

## EBSingleton

EBSingleton is an abstract class implementing singleton behavior. Subclasses implement initialization in `-initSingleton`, and clients retrieve the singleton instance via `-sharedInstance`.

## EBTime

EBTime contains a simple set of functions for measuring the difference between two instances in time, down to nanosecond resolution.

## EBUtilities

A set of generally-useful macros.

## NSTimer+EBBlockTimer

An NSTimer category for executing a block instead of a method.

## Requirements

- Mac OS 10.8 or iOS 6. (Earlier platforms have not been tested.)
- Automatic reference counting (ARC) must be enabled for the source files.

## Integration

1. Integrate [EBFoundation](https://github.com/davekeck/EBFoundation) into your project.
2. Integrate [EBConcurrentQueue](https://github.com/davekeck/EBConcurrentQueue) into your project.
3. Integrate [EBDiskCache](https://github.com/davekeck/EBDiskCache) into your project.
4. Link against libcurl.
5. Add the source files to your project.