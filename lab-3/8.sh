#!/usr/bin/env bash

# Циклический просмотр списка файлов и
# выдача сообщения при появлении заданного имени в списке.

echo "Input file name:"
read fname

while [ 1 ]
do
    for fn in `ls -a`
    do
        if [ "$fn" = "$fname" ]
        then
            echo "I see !"
            break 2
        fi
    done
done
