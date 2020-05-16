#! /bin/bash

directory=$1

mkdir -p .bin

rm -rf *.o
gcc -c linkedlist.c $directory/*.c
gcc -o .bin/a.out *.o 
.bin/a.out
rm -rf *.o