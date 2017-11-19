#!/usr/bin/env bash

# Вывод на экран списка параметров командной строки
# с указанием номера каждого параметра.

echo "0: $0"
number=1
for arg in $*
do
    echo "$number: $arg"
    let number=$number+1
done
