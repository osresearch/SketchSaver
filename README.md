This project started as a few lines of code and a [tweet](https://twitter.com/qrs/status/899281004631777280):

    Life Hack: include your Arduino sketch in the flash
    for recovery when you return to a project years later
    and have lost the source code.

It has been tested on Teensy 2 and 3 devices.

It does not hook the Arduino build scripts ([issue #1](https://github.com/osresearch/SketchSaver/issues/1) is to fix this),
so it is necessary to re-run the `make-tar` script between each
build, or at least before you put the project away for a while.

Right now you should clone this repo into your source tree.
Ideally it would be includable as a library, but the relative
include paths mess things up ([issue #2](https://github.com/osresearch/SketchSaver/issues/2)).

