#!/bin/bash

while read input
do
    if [[ $input == "q" ]]
    then echo $saved
    exit 0;
    fi;

saved=$saved$input

done;