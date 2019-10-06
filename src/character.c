#include <stddef.h>

#include "attack.h"
#include "character.h"
#include "print.h"
#include "spell.h"


void character_print_attributes(const character *character) {
  print_attribute("Name",     character->name);
  print_attribute("HP",       character->hp);
  print_attribute("MP",       character->mp);
  print_attribute("Strength", character->strength);
  print_attribute("Skill",    character->skill);
  print_attribute("Defense",  character->defense);
  print_attribute("Spirit",   character->spirit);
  print_attribute("Speed",    character->speed);
  print_attribute("Evasion",  character->evasion);
  print_attribute("Luck",     character->luck);
  print_attribute("Accuracy", character->accuracy);

  print_attribute("Number of attacks", character_attacks_count(character));

  for (int i = 0; character->attacks[i] != NULL; i++) {
    attack_print_attributes(character->attacks[i]);
  }

  print_attribute("Number of spells", character_spells_count(character));

  for (int i = 0; character->spells[i] != NULL; i++) {
    spell_print_attributes(character->spells[i]);
  }
}

int character_attacks_count(const character *character) {
  int count = 0;
  while (character->attacks[count] != NULL) { count++; }
  return count;
}

int character_spells_count(const character *character) {
  int count = 0;
  while (character->spells[count] != NULL) { count++; }
  return count;
}
