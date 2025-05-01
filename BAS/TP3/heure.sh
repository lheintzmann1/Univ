#!/bin/sh

if [ $# -ne 1 ]
then
    echo "Usage: $0 <n>" >&2
    exit 1
fi

n=$1

echo "PID: $$"

while true
do
    echo $(date | cut -d " " -f 4)
    trap "echo 'Processus $$ : Signal INT reçu'" INT
    sleep $n
done

