#arithmetic operations using Switch case

echo "Enter two Numbers : "
read n1 n2
echo "Menu : 1.Add  2.Sub  3.Mul  4.Div  5.Mod"
echo "Enter Choice : "
read ch
case $ch in
1)echo "Addition is : $((n1+n2))";;
2)echo "Subtraction is : $((n1-n2))";;
3)echo "Multiplication is : $((n1*n2))";;
4)echo "Division is : $((n1/n2))";;
5)echo "Modulous is : $((n1%n2))";;
*)echo "Enter Valid Choice..";;
esac
