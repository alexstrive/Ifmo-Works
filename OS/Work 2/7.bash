#!/bin/bash

man bash | grep -P -o "\w{4,}" | sort | uniq -c -i | sort -r -n | head -3
