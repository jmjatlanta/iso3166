#!/bin/bash

cd build

cmake -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=On \
    ..

cd ..

