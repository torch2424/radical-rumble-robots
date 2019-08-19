
void updateBattleJoypad() {
  if(joypad() & J_RIGHT) {
    fighterOne.x++;
  }
  if(joypad() & J_LEFT) {
    fighterOne.x--;
  }
  if(joypad() & J_UP) {
    fighterOne.y--;
  }
  if(joypad() & J_DOWN) {
    fighterOne.y++;
  }
}
