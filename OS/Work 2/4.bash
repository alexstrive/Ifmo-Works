#!/bin/bash

grep -P -r -h "^#\!.*/\w+$" /bin | sort | uniq -c | sort -n | tail -1 | grep -P -o "\w+$" 