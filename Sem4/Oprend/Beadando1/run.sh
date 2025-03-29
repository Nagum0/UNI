#!/bin/bash

if [ ! -d "obj/" ]; then
    mkdir obj
fi

echo "Compiling ..."
gcc -o obj/nyuszi.o -c src/nyuszi.c
gcc -o obj/main.o -c src/main.c
gcc -o nyuszi obj/*.o

if [ $? -ne 0 ]; then
    echo "Could not compile..."
    exit 1
fi

echo "Running ./nyuszi ..."
./nyuszi
