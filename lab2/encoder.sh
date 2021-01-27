#!/bin/bash

declare -a digits=( 
" 0000
00  00
00  00
00  00
 0000"
 
"1111
  11
  11
  11
111111"
 
" 2222
22  22
   22
  22
222222"
 
" 3333
33  33
   333
33  33
 3333"
 
"44  44
44  44
444444
    44
    44"
 
"555555
55
55555
    55
55555"
 
" 6666
66
66666
66  66
 6666"
 
"777777
   77
  77
 77
77"
 
" 8888
88  88
 8888
88  88
 8888"
 
" 9999
99  99
 99999
    99
 9999"
)

function encode {
   digit=$1
   lines=($(echo -ne "${digits[digit]}" | tr ' ' '*' | tr '\n' ' '))
   echo "${lines[@]}"
}
