
#!/bin/bash
echo "Enter no of elements:"
read n
echo "Enter  elements:"
for ((i=0; i< $n ;i++))
do
read nos[$i]
done
for ((i=0; i < $n ;i++))
do
    for ((j= $i; j<$n ;j++))
    do
        if [ ${nos[$i]} -gt ${nos[$j]} ];
        then
        t=${nos[$i]}
        nos[$i]=${nos[$j]}
        nos[$j]=$t
    fi
    done
done
echo "sorted array:"
for ((i=0; i<$n ;i++))
do
echo ${nos[$i]}
done




