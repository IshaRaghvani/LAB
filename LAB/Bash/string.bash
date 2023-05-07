echo "Enter a string : "
read string
echo "Enter a substring : "
read substr
count=0
l=${#string}
let l--
for i in $(seq 0 $l)
do
    v=$i
    for j in $(seq $v $l)
    do
        c=$c${string:$j:1}
        if [ $c = "" ]
        then
            break
        fi
        if [ $c = $substr ]
        then 
            let count++
        fi
    done
    c=""
done
echo "Number of occurences of substring $substr in $string is $count"