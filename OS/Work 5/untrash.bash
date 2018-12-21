
#!/bin/bash

# Format of trash.log entries:
# /full/path/to/file:h4shv4a1ue

relativePath=$PWD/$1

for i in $(grep -h $1 $HOME/trash.log)
do
  initialPath=$(echo $i | awk -F ":" '{print $1}')
  hashCode=$(echo $i | awk -F ":" '{print $2}') 

  if [[ $relativePath == $initialPath ]]
  then
    hashFileObject=$HOME/.trash/$hashCode
    
    if [ -e $hashFileObject ] 
    then
    
      echo "Restore file: $initialPath ? (yes|no)"
      read answer
      
      if [[ $answer == "yes" ]]
      then
      
	if [ -d $(dirname $initialPath) ]
	then
	  
	  if [[ -e $initialPath ]]
	  then
	    echo "Such file exists."
	    read newName
	    ln "$hashFileObject" "$(dirname $initialPath)/$newName"
	  else
	    ln $hashFileObject $initialPath
	  fi
	  
	else
	  echo "$(dirname $initialPath) was removed."
	  ln $hashFileObject $HOME/$1
	fi
	
	# Delete file hash object from trash
	# If no one else share it
	[[ ! $(grep -v $1:$hashCode $HOME/trash.log) ]] && rm $hashFileObject
	
	# Delete filename from trash log
	sed -i '/'$1:$hashCode'/d' $HOME/trash.log
	
      fi
    fi
  fi
done
