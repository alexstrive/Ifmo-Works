#!/bin/bash
today=$(date '+%d.%m.%y_%H:%M:%S')
mkdir ~/test && echo "Directory \`test\` was created." >> ~/report.tmp && touch ~/test/$today.tmp
ping -c 1 www.net_nikogo.ru || echo "Host \`net_nikogo.ru\` unreachable" >> ~/report.tmp
