#!/bin/bash

# the purpose of this project is to help learn and understand data structure and algorithm,
# clearity first, so, build and link the obj file every time is fine.

set -xe

g++ -c -ggdb ./Log/log.cpp     -o  ./objs/log.o
g++ -c -ggdb ./Stack/Stack.cpp -o  ./objs/Stack.o
g++ -c -ggdb main.cpp          -o  ./objs/main.o

g++ -ggdb -static   \
    ./objs/log.o    \
    ./objs/main.o   \
    ./objs/Stack.o  \
    -o ./objs/main

./objs/main
