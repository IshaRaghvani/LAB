echo "Enter a number : "
read n
temp=$n
num=0
while (($n>0))
do
    k=$(( n%10 ))
    num=$(( num*10 + k))
    n=$(( n/10 ))
done
if [ $temp -eq $num ];
then
echo "$temp is a Palindrome Number"
else
echo "$temp is not a Palindrome Number"
fi
echo "$num is the reverse number."
