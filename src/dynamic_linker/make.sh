#! /use/bin/sh

gcc -fPIC -shared -o Lib.so Lib.c
gcc -o Program1 Program1.c ./Lib.so 
gcc -o Program2 Program2.c ./Lib.so 