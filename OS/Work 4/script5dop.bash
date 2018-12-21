#!/bin/bash
echo "+" > 5.in
./script5.bash& > 5.in
while true
do
read line
if [[ $line == "QUIT" ]]
then
exit
fi
if [[ $line != '*' ]]
then echo $line >> 5.in
else echo "M" >> 5.in
fi
done
