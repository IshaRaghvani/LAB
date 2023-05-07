echo "Enter a string: "
read string
echo "Enter a substring: "
read substr

count=0
for ((i=0; i<${#string}; i++)); 
do
    if [[ "${string:i:${#substr}}" == "$substr" ]]; 
    then
        let count++
    fi
done

echo "Number of occurrences of substring $substr in $string is $count"
