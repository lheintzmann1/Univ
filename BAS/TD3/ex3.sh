#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Usage: $0 <début nom> <2 derniers chiffres>"
	exit 1
fi

grep "^$1 .* $2$" calepin.txt

