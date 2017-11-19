#!/usr/bin/env bash

# Запрос и ввод имени файла в текущем каталоге
# и вывод сообщения о типе файла.

echo "Input file name:"
read fname
file $fname
