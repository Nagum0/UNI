#!/bin/bash

gcc -c stack/stack.c
gcc -o a ms.c stack.o

rm stack.o

./a
echo $?