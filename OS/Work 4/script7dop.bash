#!/bin/bash
echo $$ > mypid
i=1
mode="+"
sigterm()
{
echo "STOP"
exit
}
user1()
{
mode="+"
}
user2()
{
mode="*"
}
user3()
{
mode="-"
}
trap 'sigterm' SIGTERM
trap 'user1' USR1
trap 'user2' USR2
trap 'user3' SIGURG
while true
do
case $mode in
"+")
let i=$i+2
;;
"*")
let i=$i*2
;;
"-")
let i=$i-2
;;
esac
echo $i
sleep 1
done
