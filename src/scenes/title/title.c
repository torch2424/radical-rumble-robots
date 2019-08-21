#include <gb/gb.h>

#include "title-globals.h"
#include "title-joypad.c"
#include "tiles/TitleR.h"
#include "tiles/Letters.h"
#include "../scenes.h"

void titleInit(void) {
  int i, len;
  // this C compiler is ridic, surely there's a better way
  title.levels[0].name[0] = 'O' - 'A' + 1;
  title.levels[0].name[1] = 'M' - 'A' + 1;
  title.levels[0].name[2] = 'E' - 'A' + 1;
  title.levels[0].name[3] = 'G' - 'A' + 1;
  title.levels[0].name[4] = 'A' - 'A' + 1;
  title.levels[0].name[5] = '\0';
  title.levels[0].scene_id = 1;
  title.selected_level = 0;
  title.levels[1].name[0] = 'T' - 'A' + 1;
  title.levels[1].name[1] = 'I' - 'A' + 1;
  title.levels[1].name[2] = 'T' - 'A' + 1;
  title.levels[1].name[3] = 'L' - 'A' + 1;
  title.levels[1].name[4] = 'E' - 'A' + 1;
  title.levels[1].name[5] = '\0';
  title.levels[1].scene_id = 1;
  title.selected_level = 0;
  title.cursor_location = 0;

  // The letter code broke this logo :shrug:
  set_bkg_data(TitleR_base, TitleR_tiles, TitleR_dat);
  set_bkg_tiles(4, 3, TitleR_cols, TitleR_rows, TitleR_map);
  set_bkg_tiles(4 + TitleR_rows, 3, TitleR_cols, TitleR_rows, TitleR_map);
  set_bkg_tiles(4 + TitleR_rows * 2, 3, TitleR_cols, TitleR_rows, TitleR_map);

  set_bkg_data(Letters_base, Letters_tiles, Letters_dat);
  for (i = 0; i < NUM_LEVELS; ++i) {
    for (len = 0; title.levels[i].name[len]; ++len) {};
    set_bkg_tiles(2, 12 + (i * 2), len, 1, title.levels[i].name);
  }

  SHOW_BKG;
}

void titleUpdate(void) {
  updateTitleJoypad();
  if (title.selected_level)
    transitionToNewScene(title.selected_level - 1);
}

void titleDraw(void) {
  
}
