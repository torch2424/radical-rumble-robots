#include <gb/gb.h>
#include <stdio.h>

#include "util.c"
#include "global.c"
#include "init.c"
#include "update/update.c"
#include "draw/draw.c"

void main() {

  init();

  while(1) {
    update();
    draw();
    waitForFrame();
  }
}
