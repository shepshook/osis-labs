#!/bin/bash

seed=1

function rand {
    seed=$((seed * 1103515245 + 12345))
    echo $((seed / 65536 % 32768))
}