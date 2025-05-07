#!/bin/bash

# the purpose of this project is to help learn and understand data structure and algorithm,
# clearity first, so, build and link the obj file every time is fine.

# create folder objs if not exists
if [ ! -d objs ]; then
    mkdir objs
fi

set -xe

g++ -c -ggdb ./DSLog/DSLog.cpp   -o  ./objs/DSLog.o
g++ -c -ggdb ./String/String.cpp -o  ./objs/String.o
g++ -c -ggdb main.cpp            -o  ./objs/main.o

g++ -ggdb -static    \
    ./objs/DSLog.o   \
    ./objs/String.o  \
    ./objs/main.o    \
    -o ./objs/main

./objs/main
