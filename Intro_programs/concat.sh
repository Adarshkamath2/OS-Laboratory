#concatenation of two strings

#!/bin/bash

str1=welcome
str2=to
str3=shell
str4=programming
echo "str1 : $str1"
echo "str2 : $str2"
echo "str3 : $str3"
echo "str4 : $str4"

res=$str1""$str2""$str3""$str4
echo "concatenated string"
echo $res
echo "The length of resu;ting string is :"
echo ${#res}
echo "performing various string operation "
str5="Hello_welcome_to_shell_programming"
echo "str 5: $str5"
echo "printd substring str5 from index 4 to end "
echo ${str5:4}
echo "prints the substring of length 10 of str5 from index 4"
echo ${str5:4:10}
echo "Deletes the shortest matching substring from front(_)"
echo ${str5#*_}
echo "Deletes the shortest matching substring from back(_)"
echo ${str5%_*}
echo "Deletes the longest matching substring from front(_)"
echo ${str5##*_}
echo "Deletes the longest matching substring from back(_)"
echo ${str5%%_*}
