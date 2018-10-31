#!/bin/bash

grep -P "\(WW\)" /var/log/Xorg.0.log | sed -E "s/\(WW\)/Warning: /" > full.log
grep -P "\(II\)" /var/log/Xorg.0.log | sed -E "s/\(II\)/Information: /" >> full.log
