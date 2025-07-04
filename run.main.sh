#!/bin/bash

# the purpose of this project is to help learn and understand data structure and algorithm,
# clearity first, so, build and link the obj file every time is fine.

# create folder objs if not exists
if [ ! -d objs ]; then
    mkdir objs
fi

set -xe

g++ -ggdb ./Sort/01_insertSort/insert_sort.c  -o  ./objs/insert_sort

./objs/insert_sort
