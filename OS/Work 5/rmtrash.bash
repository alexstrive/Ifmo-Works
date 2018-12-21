#!/bin/bash

filename=$1
trashPath=$HOME/.trash
trashLogPath=$HOME/trash.log

hashValue=$(md5sum $1 | awk '{ print $1 }')

[ ! -d $trashPath ] && mkdir $trashPath
[ ! -e $trashLogPath ] && touch $trashLogPath

ln $filename "$trashPath/$hashValue"
rm $filename

echo "$PWD/$filename:$hashValue" >> $trashLogPath
