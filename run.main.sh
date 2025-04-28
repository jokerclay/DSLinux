#!/bin/bash

# the purpose of this project is to help learn and understand data structure and algorithm,
# clearity first, so, build and link the obj file every time is fine.

set -xe

g++ -c -ggdb ./Log/log.cpp   -o  ./objs/log.o
g++ -c -ggdb ./List/List.cpp -o  ./objs/List.o
g++ -c -ggdb main.cpp        -o  ./objs/main.o

g++ -ggdb         \
    ./objs/log.o  \
    ./objs/main.o \
    ./objs/List.o \
    -o ./objs/main

./objs/main
