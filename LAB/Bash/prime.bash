#!/bin/bash
echo "enter no:"
read n
for (( i=2 ;i<=$n/2 ;i++))
    do
    ans=$((n%i))
    if [ $ans -eq 0 ];
    then
        echo "not prime"
        exit 0
    fi
done
echo "prime"


