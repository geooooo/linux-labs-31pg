#!/usr/bin/env bash

# Циклическое чтение системного времени
# и очистка экрана в заданный момент.

prev_date=""
while [ 1 ]
do
    cur_date=`date '+%T'`
    if [ "$prev_date" <> "$cur_date" ]
    then
        prev_date=$cur_date
        clear
        echo $cur_date
    fi
done
