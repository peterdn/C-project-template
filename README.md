# C project template [![Build Status](https://travis-ci.org/peterdn/C-project-template.svg?branch=master)](https://travis-ci.org/peterdn/C-project-template)

This is a C project template with the following features:

 - CMake build scripts for building libraries, applications, and tests.
 - Integrated with
   [Unity unit test framework](http://www.throwtheswitch.org/unity/).

## Usage

Simply build with CMake:

    git clone git@github.com:peterdn/C-project-template.git my-project
    cd $_/build
    cmake ..
    make -j

To run tests:

    make test

## Project directory structure

 - app/ -- Application source code.
 - include/ -- Library headers.
   - example/ -- Headers for an example library.
 - src/ -- Library source code.
 - test/ -- Test source code.
   - unity/ -- Unity test framework source.

## Build directory structure

 - bin/ -- Application binaries.
   - test/ -- Test binaries.
 - lib/ -- Libraries.

## License

Distributed under the BSD-2-Clause license. See LICENSE for details.

[Unity unit test framework](http://www.throwtheswitch.org/unity/) is
distributed under the MIT license. See test/unity/license.txt for details.
