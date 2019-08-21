
#include "battle/battle.h"
#include "title/title.h"

const int TITLE_SCENE_ID = 1;
const int BATTLE_SCENE_ID = 0;

typedef struct SceneState {
  int shouldInit;
  int stateId;
} SceneState;

SceneState sceneState = { 1, TITLE_SCENE_ID};

void transitionToNewScene(int newScene) {
  sceneState.stateId = newScene;
  sceneState.shouldInit = 1;
}

void tickBattle(void) {
  battleUpdate();
  battleDraw(); 
}

void tickTitle(void) {
  titleUpdate();
  titleDraw();
}

// This is an array of function pointers; the C syntax for it is not clear
static void (*initFunc[])(void) = { battleInit, titleInit  };
static void (*tickFunc[])(void) = { tickBattle, tickTitle };

void sceneTick(void) {
  // set up and tear down of scenes should be handled in a scene graph
  if (sceneState.shouldInit) {
    initFunc[sceneState.stateId]();
    sceneState.shouldInit = 0;
  }
  tickFunc[sceneState.stateId]();
}

