#pragma once

#include <stdbool.h>

#include "action.h"
#include "character.h"


#define MAX_POWER 100

typedef struct attack {
  action;
  int power;
} attack;

int attack_calculate_damage(character *, character *, attack *);
bool attack_determine_evade(character *, character *);
bool attack_determine_critical(character *);
void attack_print_attributes(const attack *);
