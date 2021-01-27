#!/bin/bash

source ./encoder.sh
source ./generator.sh

width=$(($(tput cols) - 46))
height=$(($(tput lines) - 6))

while true
do
    clear

    if [ $(date +%s) -gt $(($timer + 10)) ]
    then
        timer=$(date +%s)
        x=$(($(rand) % $width + 1))
        echo $x
        y=$(($(rand) % $height + 1))
    fi

    clock_digits=$(date "+%H%M%S")

    offset=0
    for ((count=0; count < ${#clock_digits}; count++)); do
        if [ $count -eq 2 ] || [ $count -eq 4 ]
        then
            echo -e "\e[$(($y + 1));$(($x + $count * 7 + $offset))Ho"
            echo -e "\e[$(($y + 3));$(($x + $count * 7 + $offset))Ho"
            offset=$(($offset + 2))
        fi
        lines=($(encode ${clock_digits:$count:1}))
        for i in "${!lines[@]}"; do
            lines[$i]=$(echo "${lines[$i]}" | tr '*' ' ')
            echo -e "\e[$(($y + $i));$(($x + $count * 7 + $offset))H${lines[$i]}"
        done
    done

    sleep 1
done
