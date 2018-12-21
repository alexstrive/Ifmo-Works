#!/bin/bash
status=""
for pid in $(ps -A -o pid | tail -n +2) 
do
  file="/proc/"$pid"/status"
  file1="/proc/"$pid"/sched"
  ppid=$(grep -E -h -s -i "ppid:\s(.+)" $file | grep -o "[0-9]\+")

  nr_switches=$(grep -E -h -s -i "nr_switches(.+)" "/proc/$pid/sched" | awk '{print $3}')
  sum_exec_runtime=$(grep -E -h -s -i "se.sum_exec_runtime(.+)" "/proc/$pid/sched" | awk '{print $3}')
  
  if [[ nr_switches -eq 0 ]]
  then nr_switches=1
  fi
  
  sleepavg=$(bc -l <<< "$sum_exec_runtime/$nr_switches");
  
  if [[ $ppid != "" ]]
  then status=$status"ProcessID="$pid" : Parent_ProcessID="$ppid" : Average_Sleeping_Time="$sleepavg$'\n'
  fi
done
echo "$status" | sort -t " " -k2 > 5.txt
