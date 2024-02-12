#!/bin/bash

echo "Input a number: "
read n

if ((n % 2 == 0)) then
    echo "The number $n is even!"
else
    echo "The number $n is odd!"
fi