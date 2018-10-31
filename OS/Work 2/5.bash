#!/bin/bash

awk '{ FS=":"; print $3, $1;}' /etc/passwd | sort -n