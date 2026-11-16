#!/bin/bash

awk -F: '$2 >= 10 {print $1 $2}' 2.txt
