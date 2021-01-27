#!/bin/bash

function rand {
    val=$(($(date +%s) * 1103515245 + 12345))
    echo $(($val / 65536 % 32768))
}
