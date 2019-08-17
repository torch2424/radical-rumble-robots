
#include "smile.c"

void draw() {
  set_sprite_data(0, 8, smile);
  set_sprite_tile(0, 0);
  move_sprite(0, 50, 50);
}
