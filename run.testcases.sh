#!/bin/bash

echo "============="
echo "  testcases  "
echo "============="

echo "--------"
echo "  list1 "
echo "--------"

set -xe
g++ -c -ggdb ./Log/log.cpp   -o  ./objs/log.o
g++ -c -ggdb ./List/List.cpp -o  ./objs/List.o
g++ -c -ggdb ./TestCases/list/list1.cpp        -o  ./objs/list1.o

g++ -ggdb         \
    ./objs/log.o  \
    ./objs/List.o \
    ./objs/list1.o \
    -o ./objs/list1

./objs/list1
