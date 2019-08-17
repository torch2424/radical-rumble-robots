
#include "sprites/smile.c"

void draw() {
  set_sprite_data(0, 8, smile);
  set_sprite_tile(fighterOne.spriteId, 0);
  move_sprite(fighterOne.spriteId, fighterOne.x, fighterOne.y);
}
