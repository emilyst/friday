#pragma once

#include "character.h"


typedef struct enemy {
  character;
  int xp_awarded;
  int gold_awarded;
} enemy;

void enemy_print_attributes(const enemy *);
