#pragma once

#include "attack.h"
#include "character.h"


typedef struct spell {
  attack;
  int cost;
} spell;

void spell_use(character *, character *, spell *);
void spell_print_attributes(spell *);
