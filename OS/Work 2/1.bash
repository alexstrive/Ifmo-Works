#!/bin/bash
grep -P -r -h "^[\w\s.,:\[\]]*:?\s?ACPI.*" /var/log/

grep -P "/[\w/\.]*" errors.log