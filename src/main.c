#include <gb/gb.h>
#include <stdio.h>

#include "util.c"
#include "global.c"
#include "scenes/scenes.c"

void main() {
  while(1) {
    sceneTick();
    waitForFrame();
  }
}
