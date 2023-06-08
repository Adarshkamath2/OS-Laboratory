#!/bin/bash
#Shell script to find maximum of three numbers

echo "Enter three numbers: "
read n1
read n2
read n3

large=$n1
if [ $n2 -gt $large ];then
    large=$n2
fi

if [ $n3 -gt $large ];then
    large=$n3
fi

echo "Largest: $large"
