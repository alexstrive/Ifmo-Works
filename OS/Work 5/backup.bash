#!/bin/bash
backupParentDirectory="$HOME/"
sourceDirectory="$HOME/source/"

todayDate=$(date "+%F")
backupPrefix="Backup-"
backupReport="$HOME/backup-report"
todaySeconds=$(date --date=$todayDate "+%s")

lastBackupDirectory=$(ls $backupParentDirectory -1 | grep -E "Backup-[0-9]{4}-[0-9]{2}-[0-9]{2}" | sort -r -k2 | head -1)
lastBackupSeconds=$(date --date=$(ls $backupParentDirectory -1 | grep -Eo "Backup-[0-9]{4}-[0-9]{2}-[0-9]{2}" | sort -r -k2 | head -1 | sed "s/^Backup-//") "+%s")
let dateDiff=($todaySeconds\-$lastBackupSeconds)/60/60/24

if [ "$dateDiff" -le 7 ]
then
  currentBackupDirectory=$backupParentDirectory$lastBackupDirectory"/"
else
  mkdir $backupParentDirectory$backupPrefix$todayDate
  currentBackupDirectory=$backupParentDirectory$backupPrefix$todayDate"/"
  isDirectoryCreated=1
fi

isDirectoryCreated=0

if [ "$isDirectoryCreated" == "1" ]
then
  echo "Created at "$todayDate >> $backupReport
  echo "Files: " >> $backupReport
  for file in $(ls $sourceDirectory -1)
  do
    cp $sourceDirectory$file $currentBackupDirectory$file
    echo $file >> $backupReport
  done
else
  echo "Updated at "$todayDate"" >> $backupReport
  echo "Files: " >> $backupReport
  for file in $(ls $sourceDirectory -1)
  do
    currentFilePath=$currentBackupDirectory$file
    if [ -f currentFilePath ];
    then
    source_size=$(stat $sourceDirectory$file -c%s)
    actual_size=$(stat $currentFilePath -c%s)
      if [[ "$source_file" != "$actual_size" ]];
      then
	mv $currentFilePath $currentFilePath"."$todayDate
	cp $sourceDirectory$file $currentFilePath
	echo "New version of file "$file" found. Old version moved to "$file.$todayDate"" >> $backupReport
      fi
    else
      cp $sourceDirectory$file $currentFilePath
      echo -e '  '$file >> $backupReport
    fi
  done
fi
