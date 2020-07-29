#pragma once


#define MAX_HP       9999
#define MAX_MP       9999

/* Think of these as percentages. */
#define MAX_STRENGTH 100
#define MAX_SKILL    100
#define MAX_DEFENSE  100
#define MAX_SPIRIT   100
#define MAX_SPEED    100
#define MAX_EVASION  100
#define MAX_LUCK     100
#define MAX_ACCURACY 100

typedef struct character {
  char *name;
  short hp,
      mp,
      strength,
      skill,
      defense,
      spirit,
      speed,
      evasion,
      luck,
      accuracy;
  struct spell **spells;
  struct attack **attacks;
} character;

void character_print_attributes(const character *);
int character_attacks_count(const character *);
int character_spells_count(const character *);
