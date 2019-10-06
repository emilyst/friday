#pragma once

#include "character.h"


typedef struct player {
  character;
  int xp;
  int gold;
} player;

void player_print_attributes(const player *);
