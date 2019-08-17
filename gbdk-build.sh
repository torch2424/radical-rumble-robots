#!/bin/bash

set -e

echo " "
echo "============================================="
echo "Compiling Game"
echo "============================================="
echo " "

mkdir -p dist
cd dist
lcc -Wa-l -Wl-m -Wl-j -c -o main.o ../src/main.c
lcc -Wa-l -Wl-m -Wl-j -o main.gb main.o

echo " "
echo "============================================="
echo "Done!"
echo "============================================="
echo " "

