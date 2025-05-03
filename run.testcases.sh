#!/bin/bash

# create folder objs if not exist
if [ ! -d objs ]; then
    mkdir objs
fi

banner() {
    local msg="$1"
    echo "--------------------------------------------------------"
    printf "                      %s\n" "$msg"
    echo "--------------------------------------------------------"
}


echo "============="
echo "  testcases  "
echo "============="

banner "sqList"
set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp           -o  ./objs/DSLog.o
g++ -c -ggdb ./List/List.cpp             -o  ./objs/List.o
g++ -c -ggdb ./TestCases/list/sqList.cpp -o  ./objs/sqList.o

g++ -ggdb -static   \
    ./objs/DSLog.o  \
    ./objs/List.o   \
    ./objs/sqList.o \
    -o ./objs/sqList

./objs/sqList
set +xe

banner "linkedList"

set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp               -o  ./objs/DSLog.o
g++ -c -ggdb ./List/List.cpp                 -o  ./objs/List.o
g++ -c -ggdb ./TestCases/list/linkedList.cpp -o  ./objs/linkedList.o

g++ -ggdb -static       \
    ./objs/DSLog.o      \
    ./objs/List.o       \
    ./objs/linkedList.o \
    -o ./objs/linkedList

./objs/linkedList
set +xe

banner "sqStack"
set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp             -o  ./objs/DSLog.o
g++ -c -ggdb ./Stack/Stack.cpp             -o  ./objs/Stack.o
g++ -c -ggdb ./TestCases/stack/sqStack.cpp -o  ./objs/sqStack.o

g++ -ggdb -static    \
    ./objs/DSLog.o   \
    ./objs/Stack.o   \
    ./objs/sqStack.o \
    -o ./objs/sqStack

./objs/sqStack
set +xe


banner "linkedStack"
set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp                 -o  ./objs/DSLog.o
g++ -c -ggdb ./Stack/Stack.cpp                 -o  ./objs/Stack.o
g++ -c -ggdb ./TestCases/stack/linkedStack.cpp -o  ./objs/linkedStack.o

g++ -ggdb -static        \
    ./objs/DSLog.o       \
    ./objs/Stack.o       \
    ./objs/linkedStack.o \
    -o ./objs/linkedStack

./objs/linkedStack
set +xe

banner "circleSqQueue"

set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp                 -o  ./objs/DSLog.o
g++ -c -ggdb ./Queue/Queue.cpp                 -o  ./objs/Queue.o
g++ -c -ggdb ./TestCases/queue/circleQueue.cpp -o  ./objs/circleQueue.o

g++ -ggdb -static        \
    ./objs/DSLog.o       \
    ./objs/Queue.o       \
    ./objs/circleQueue.o \
    -o ./objs/circleQueue

./objs/circleQueue
set +xe

