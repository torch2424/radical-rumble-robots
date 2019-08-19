
#include "battle/battle.c"

const int BATTLE_SCENE_ID = 1;

struct SceneState {
  int shouldInit;
  int stateId;
};

struct SceneState sceneState = {1, 1};

void sceneTick() {
  if (sceneState.stateId == BATTLE_SCENE_ID) {
    
    if (sceneState.shouldInit > 0) {
      battleInit();
      sceneState.shouldInit = 0;
    }

    battleUpdate();
    battleDraw(); 
  }
}

