#!/usr/bin/env bash

# Переход в другой каталог, формирование файла
# с листингом каталога и возвращение в исходный каталог.

src_path=`pwd`
dst_path="./dir"
fname="$src_path/res4.txt"

cd $dst_path
ls > $fname
cd $src_path
