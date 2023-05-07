factorial(){
    if (( $1 <= 1 )); 
    then
    echo 1
    else
    last=$(factorial $(( $1 - 1 )))
    echo $(( $1 * last ))
    fi
}

echo "Enter a number : "
read num
if [ $num -eq 0 ];
then
echo "1 is the factorial of number $num"
else
factorial $num
fi

#iterative

echo "Enter a number : "
read num
factorial=1
for (( i=2; i<=$num; ++i ))
do
factorial=$((factorial*i))
done
echo "$factorial is the factorial of number $num"