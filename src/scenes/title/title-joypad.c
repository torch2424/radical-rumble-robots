#include <gb/gb.h>
#include "title-types.h"

void updateTitleJoypad() {
  int jp = joypad();
  if (jp & J_UP) {
    if (title.cursor_location > 0) {
      title.cursor_location -= 1;
    }
  }
  if (jp & J_DOWN) {
    if (title.cursor_location < NUM_LEVELS) {
      title.cursor_location += 1;
    }
  }
  if (jp & J_A || jp & J_START) {
    // lmao
    title.selected_level = title.cursor_location + 1;
  }
}
