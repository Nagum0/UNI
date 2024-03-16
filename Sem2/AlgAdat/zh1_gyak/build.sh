#!/bin/bash

gcc -c stack/stack.c
gcc -o a main.c stack.o

rm stack.o

./a
echo $?