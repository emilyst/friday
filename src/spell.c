#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "attack.h"
#include "print.h"
#include "spell.h"


int spell_calculate_damage(character *attacker,
                           character *target,
                           attack *attack) {
  if (attack_determine_evade(attacker, target)) return 0;

  double damage = attacker->skill + attack->power;
  damage *= ((MAX_SPIRIT + 10) - target->spirit) / 4;
  damage *= attack->power / MAX_POWER;

  return damage ? damage : 1;
}

void spell_print_attributes(spell *spell) {
  attack_print_attributes((attack *) spell);
  print_attribute("Cost", spell->cost);
}
