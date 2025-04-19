#!/bin/bash

echo "./while test.ok > test.asm"
./while test.ok > test.asm

echo "cat test.asm"
cat test.asm

echo "nasm -f elf -o test.o test.asm"
nasm -f elf -o test.o test.asm

echo "gcc -m32 -o test test.o io.c"
gcc -m32 -o test test.o io.c
