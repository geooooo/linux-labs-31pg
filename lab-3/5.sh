#!/usr/bin/env bash

# Запрос и ввод имени пользователя, сравнение с текущим
# логическим именем пользователя и вывод сообщения: верно/неверно.

login2="v@sia"
echo "Input login:"
read login1
if [ "$login1" = "$login2" ]
then
    echo "SUCCESS"
else
    echo "FAILURE"
fi
