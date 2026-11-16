#!/bin/bash
if [ -z "$1" ]; then
        echo "надо писать which.sh <имя>"
        exit 1
fi
IFS=':'
for dir in $PATH; do
	path="$dir/$1"
	if [ -x "$path" ] && [ -f "$path" ]; then
		echo "$path"
		exit 0
	fi
done
echo "$1 nf"
exit 1
