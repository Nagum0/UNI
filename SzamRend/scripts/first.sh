#!/bin/bash

if [ $# -eq 1 ] 
then
    echo $1
else
    echo "Incorrect usage!"
    echo "Correct usage => ./first.sh <parameter>"
fi

for i in 1 2 3 4 5 
do
    echo $i
done

for ((  ))