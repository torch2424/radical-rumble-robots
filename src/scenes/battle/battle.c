#include "battle-globals.c"
#include "battle-joypad.c"

#include "tiles/Robot.c" 

void battleInit() {

  // For loops
  int i;

  // Initialize our background
  SHOW_BKG;

  // Initialize our sprites
  SPRITES_8x8;
  SHOW_SPRITES;

  // Set up our sprite data
  set_sprite_data(0, 4, Robot);

  // Set up our fighters
  fighterOne.x = 50;
  fighterOne.y = 50;
  for (i = 0; i < 4; i++) {
    fighterOne.spriteIds[i] = i;
    fighterOne.tileNums[i] = i;
  }
}

void battleUpdate() {
  updateBattleJoypad();
}

void battleDraw() {
  // For loops
  int x;
  int y;

  // Draw our fighters(16x16)
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      set_sprite_tile(fighterOne.spriteIds[(x) + (y * 2)], fighterOne.tileNums[(x) + (y * 2)]);
      move_sprite(fighterOne.spriteIds[(x * 2) + (y)], fighterOne.x + (x * 8), fighterOne.y + (y * 8));
    }
  }
}