#!/bin/bash
result=1
operate='+'
tail -n 0 -f 5.in | while true
do
read line
case $line in
'+')
operate='+'
echo "Adding numbers"
;;
M)
operate='*'
echo "Multiplying numbers"
;;
[0-9]*)
if [[ $operate == '+' ]]
then
let result=$result+$line
else
let result=$result\*$line
fi
echo "$operate$line = $result"
;;
*)
echo "Error!"
;;
esac
done
