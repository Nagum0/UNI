#!/bin/bash

if [ $# -eq 1 ]
then
    echo `cat $1`
else
    echo "u messed up..."
fi