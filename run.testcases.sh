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


banner "sqStack - bracket matching"
set -xe

cp ./TestCases/stack/bracketMathchingCase* ./objs/
g++ -c -ggdb ./DSLog/DSLog.cpp                     -o  ./objs/DSLog.o
g++ -c -ggdb ./Stack/Stack.cpp                     -o  ./objs/Stack.o
g++ -c -ggdb ./TestCases/stack/bracketmatching.cpp -o  ./objs/bracketmatching.o

g++ -ggdb -static            \
    ./objs/DSLog.o           \
    ./objs/Stack.o           \
    ./objs/bracketmatching.o \
    -o ./objs/bracketmatching

./objs/bracketmatching
set +xe


banner "Array"
set -xe
g++ -c -ggdb ./Array/Array.cpp           -o  ./objs/Array.o
g++ -c -ggdb ./TestCases/array/array.cpp -o  ./objs/array.o

g++ -ggdb -static   \
    ./objs/Array.o  \
    ./objs/array.o  \
    -o ./objs/array

./objs/array
set +xe


banner "String"
set -xe
g++ -c -ggdb ./DSLog/DSLog.cpp                 -o  ./objs/DSLog.o
g++ -c -ggdb ./String/String.cpp           -o  ./objs/String.o
g++ -c -ggdb ./TestCases/string/string.cpp -o  ./objs/string.o

g++ -ggdb -static   \
    ./objs/DSLog.o  \
    ./objs/String.o  \
    ./objs/string.o  \
    -o ./objs/string

./objs/string
set +xe


banner "Binary Tree"
set -xe
g++ -c -ggdb ./Tree/BinaryTree.cpp     -o  ./objs/BinaryTree.o
g++ -c -ggdb ./Queue/Queue.cpp         -o  ./objs/Queue.o
g++ -c -ggdb ./TestCases/tree/tree.cpp -o  ./objs/tree.o

g++ -ggdb -static        \
    ./objs/BinaryTree.o  \
    ./objs/Queue.o       \
    ./objs/tree.o        \
    -o ./objs/tree

./objs/tree
set +xe

