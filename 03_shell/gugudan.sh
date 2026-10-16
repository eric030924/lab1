#!/bin/bash

# 1. for 반복문
echo "===== FOR ====="

for dan in {2..9}
do
    for i in {1..9}
    do
        echo "$dan x $i = $((dan * i))"
    done
done

# 2. while 반복문
echo "===== WHILE ====="

dan=2

while [ $dan -le 9 ]
do
    i=1

    while [ $i -le 9 ]
    do
        echo "$dan x $i = $((dan * i))"
        let i++
    done

    let dan++
done

# 3. until 반복문
echo "===== UNTIL ====="

dan=2

until [ $dan -gt 9 ]
do
    i=1

    until [ $i -gt 9 ]
    do
        echo "$dan x $i = $((dan * i))"
        let i++
    done

    let dan++
done
