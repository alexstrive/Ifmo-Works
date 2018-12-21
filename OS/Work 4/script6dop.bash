#!/bin/bash
echo $$ > mypid
echo "RUNNING"
i=0
exiting='0'

sigterm()
{
    exiting='1'
}

trap 'sigterm' SIGTERM

while true
do
    case $exiting in
    0)
        echo $i
        let i=$i+1
    ;;
    1)
        echo "STOP"
        exit
    ;;
    esac

    sleep 1
done
