#!/bin/bash

COUNTER=0

while [ $COUNTER -lt 10000 ]; do
    ./a.out > /dev/null
    echo $?
    let COUNTER=COUNTER+1
done
