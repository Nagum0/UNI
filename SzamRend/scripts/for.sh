#!/bin/bash

for i in 1 2 3 4 5
do
    echo "Iterator: $i"
done

for ((i = 1; i <= 5; i++))
do
    echo "Iterator 2: $i"
done