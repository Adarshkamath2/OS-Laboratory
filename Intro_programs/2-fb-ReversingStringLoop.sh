#Reverse a String using loop
#!/bin/bash

echo "Enter a string : "
read str
length=${#str}

for((i=$length-1;i>=0;i--))
	do
	REV=$REV${str:$i:1}
	done
echo "the reverse of string using loop is : "
echo $REV

echo "To check Palindrome"

	if [ $str = $REV ]
then
	echo "$str is a palindrome"
else
echo "$str is not a palindrome"
fi
