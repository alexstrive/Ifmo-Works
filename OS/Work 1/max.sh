#!/bin/bash

let max=$1

if [[ $2 -gt $max ]]
then let max=$2
fi;

if [[ $3 -gt $max ]]
then let max=$3
fi;

echo $max;

exit 0;