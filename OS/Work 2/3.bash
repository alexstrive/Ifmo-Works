#!/bin/bash

grep -P -r -o -h -s -a "[\w.]+@[\w_]+(\.\w+)+" /etc/* | uniq | awk '{printf("%s, ",$1)}' > email.lst
