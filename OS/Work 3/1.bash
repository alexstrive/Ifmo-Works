
ps -U admin -o pid,command | tail -n +2 | sed -r "s/\s([0-9]+)\s(.+)$/\1:\2/" > "admin's processes"

