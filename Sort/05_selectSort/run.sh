#!/bin/bash

set -xe

gcc  -ggdb ./select_sort.c -o select_sort

./select_sort
