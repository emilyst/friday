#include "print.h"
#include "enemy.h"


void enemy_print_attributes(const enemy *enemy) {
  character_print_attributes((const character *) enemy);
}
