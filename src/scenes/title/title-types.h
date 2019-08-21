#ifndef RRR_TITLE_TYPES
#define RRR_TITLE_TYPES

#define LEVEL_NAME_LEN 16
#define NUM_LEVELS 2

typedef struct Level {
  char name[LEVEL_NAME_LEN];
  int scene_id;
} Level;

typedef struct Title {
  Level levels[NUM_LEVELS];
  int selected_level;
  int cursor_location;
} Title;

#endif // RRR_TITLE_TYPES
