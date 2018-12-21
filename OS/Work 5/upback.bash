#!/bin/bash

backupParentDirectory="$HOME/"
restoreDirectory="$HOME/restore/"
backupPrefix="Backup-"

[[ ! -d "$restoreDirectory" ]] && mkdir $restoreDirectory

latestBackup=$(find $backupParentDirectory$backupPrefix* -maxdepth 0 | sort -n | tail -n 1)"/"

for file in $(ls $latestBackup -1);
do
  if [ "$(echo $file | grep -Eo "Backup-[0-9]{4}-[0-9]{2}-[0-9]{2}")" == "" ];
  then
    if [ "$(ls $latestBackup$file.* 2>/dev/null | grep -Eo "[0-9]{4}-[0-9]{2}-[0-9]{2}")" == "" ];
    then
	    cp $latestBackup$file $restoreDirectory$file
    fi
  fi
done