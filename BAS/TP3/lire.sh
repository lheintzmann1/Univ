#!/bin/sh

tempfile="temp.txt"

while read -r line
do
    if [ -z "$line" ]
    then
        break
    fi
    echo "$line" >> $tempfile
    trap "rm $tempfile; exit 1" INT
done

cat $tempfile

rm $tempfile

exit 0
