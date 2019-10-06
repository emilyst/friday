#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef __linux
#include <bsd/stdlib.h>
#endif

#include "attack.h"
#include "print.h"


int attack_calculate_damage(character *attacker,
                            character *target,
                            attack *attack) {
  if (attack_determine_evade(attacker, target)) return 0;

  double damage = pow(attacker->strength, 2) / 10 + attacker->strength;
  damage *= ((MAX_DEFENSE + 10) - target->defense) / MAX_DEFENSE;
  damage *= attack->power / 10;
  damage = ceil(damage);

  if (attack_determine_critical(attacker)) damage *= 2;

  return damage ? damage : 1;
}

bool attack_determine_evade(character *attacker, character *target) {
  double attacker_hit = attacker->accuracy / (double) MAX_ACCURACY;
  double target_evade = target->evasion / (double) MAX_EVASION + attacker_hit;
  return attacker_hit * target_evade * (double) MAX_EVASION > (double) arc4random_uniform(100);
}

bool attack_determine_critical(character *attacker) {
  return (unsigned int) attacker->luck > arc4random_uniform(MAX_LUCK);
}

void attack_print_attributes(const attack *attack) {
  print_attribute("Name",  attack->name);
  print_attribute("Power", attack->power);
}
