#!/bin/bash

start=$(date +%s%3N)
eval $1
end=$(date +%s%3N)
duration=$((end - start))
echo "$duration ms"
