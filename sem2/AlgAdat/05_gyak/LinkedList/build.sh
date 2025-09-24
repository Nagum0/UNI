#!/bin/bash

gcc -c node.c
gcc -c hsls/hsls.c
gcc -c sls/sls.c
gcc -o a main.c hsls.o sls.o node.o
rm sls.o
rm hsls.o
rm node.o

./a
echo $?
