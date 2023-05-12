#Addition of two Matrices

#!/bin/bash
m=3
n=3

declare -A x
declare -A y
declare -A z

echo "Enter the elements of First 3*3 matrix : "
for((i=0;i<3;i++))
do
for((j=0;j<3;j++))
do
read x[$i,$j]
done
done

echo "Enter the elements of Second 3*3 matrix : "
for((i=0;i<3;i++))
do
for((j=0;j<3;j++))
do
read y[$i,$j]
done
done
echo "First matrix : "
echo
for((i=0;i<3;i++))
do
for((j=0;j<3;j++))
do
	echo -ne "${x[$i,$j]}"
done
echo
done

echo "Second matrix : "
echo
for((i=0;i<3;i++))
do
for((j=0;j<3;j++))
do
	echo -ne "${y[$i,$j]}"
done
echo
done

echo "Resultant matrix : "
echo
for((i=0;i<3;i++))
do
for((j=0;j<3;j++))
do
	z[$i,$j]=$((x[$i,$j]+y[$i,$j]))
	echo -ne "${z[$i,$j]}"
done
echo
done
