#!/bin/bash

source ./encoder.sh
source ./generator.sh

clear
width=$(($(tput cols) - 42))
height=$(($(tput lines) - 6))
seed=$(date +%s)
start=$(date +%s)

while true
do
    clear

    # if [ $(date +%s) > $(($start + 10)) ]
    # then
    #     start=$(date +%s)
    #     x=$(($(rand) % $width + 1))
    #     y=$(($(rand) % $height + 1))
    # fi

    clock_digits=$(date "+%H%M%S")

    for ((count=0; count < ${#clock_digits}; count++)); do
        lines=($(encode ${clock_digits:$count:1}))
        for i in "${!lines[@]}"; do
            lines[$i]=$(echo "${lines[$i]}" | tr '*' ' ')
            echo -e "\e[$(($y + $i));$(($x + $count * 7))H${lines[$i]}"
        done
    done

    
    sleep 1
done
