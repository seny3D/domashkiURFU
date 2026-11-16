#!/bin/bash

seq 1 10
echo "new";
for ((i=1; i<=10;i++)); do echo "$i"; done
echo "new";
for i in {1..10}; do echo "$i"; done
echo "new";
printf '%s\n' {1..10}
echo "new";
i=1; while [ "$i" -le 10 ]; do echo "$i"; ((i++)); done;
echo "new";
yes "" | head -n 10 | nl -v 1
echo "new";
