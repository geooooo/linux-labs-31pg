#!/usr/bin/env bash

# Присвоение переменным А, В и С значений 10, 100 и 200,
# вычисление и вывод результатов по формуле D=(A*2 + B/3)*C.

A=10
B=100
C=200
let D=($A*2+$B/3)*$C

echo $D
