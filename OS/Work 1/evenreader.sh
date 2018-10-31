#!/bin/bash
let counter=0;

while read input
do
    if [[ $((input%2)) -eq 0 ]]
    then 
        echo "Even was found!"
        echo $counter "was countered"
        exit 0;
    fi;

counter=$(($counter+1))

done;