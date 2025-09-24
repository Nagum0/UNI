#!/bin/bash

echo "./while tests/test.ok > tests/test.asm"
./while tests/test.ok > tests/test.asm

echo "cat tests/test.asm"
cat tests/test.asm

echo "nasm -f elf -o tests/test.o tests/test.asm"
nasm -f elf -o tests/test.o tests/test.asm

echo "gcc -m32 -o tests/test tests/test.o io.c"
gcc -m32 -o tests/test tests/test.o io.c
