#concatenation of two strings
#!/bin/bash

echo "Enter the Strings : "
read str1 
read str2
if [ "$str1" = "$str2" ] 
then echo "$str1 and $str2 are the same"
else if [ "$str1" \> "$str2" ] 
then echo "$str1 is greater than $str2"
else
	echo "$str2 is greater than $str1"	
fi
fi
