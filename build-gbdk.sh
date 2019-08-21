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
lcc -Wa-l -Wl-m -Wl-j -c -o battle.o ../src/scenes/battle/battle.c
lcc -Wa-l -Wl-m -Wl-j -c -o title.o ../src/scenes/title/title.c

echo " "
echo "============================================="
echo "Linking Game!"
echo "============================================="
lcc -Wa-l -Wl-m -Wl-j -o main.gb main.o battle.o title.o

echo " "
echo "============================================="
echo "Done!"
echo "============================================="
echo " "

