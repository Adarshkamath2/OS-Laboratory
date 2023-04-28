#Array operation
#!/bin/bash

str1=welcome
str2=to
str3=shell
str4=programming

arr=($str1$str2$str3$str4)
length=${#arr[@]}
echo "The length of the array is : "$length""
echo "The array elements are : "
for((i = 0;i<$length;i++))
	do
		echo ${arr[i]}
	done
