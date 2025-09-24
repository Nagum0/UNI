#!/bin/bash

mods=""
os=()

flag_s=false
flag_q=false

# Checking the input flags:
while [[ $# -gt 0 ]]; do
    case "$1" in
        "-s")
            flag_s=true
            ;;
        "-q")
            flag_q=true
            ;;
        *)
            echo "Unkown flag: $1"
            exit 1
            ;;
    esac
    shift
done

# Constructing the command:
if [ "$flag_s" = true ]; then
    mods="$mods stack_magic/stack.c"
    os+=("stack.o")
fi

if [ "$flag_q" = true ]; then
    mods="$mods src_que/queue/que.c"
    os+=("que.o")
fi

# Running gcc:
gcc -c $mods LinkedList/hsls/hsls.c LinkedList/node.c
gcc -o a main.c ${os[@]} hsls.o node.o

for o in ${os[@]}; do
    rm $o
done

./a
if [ $? -eq 0 ]; then
    echo "True"
else
    echo "False"
fi