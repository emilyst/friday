#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "attack.h"
#include "battle.h"
#include "character.h"
#include "enemy.h"
#include "player.h"
#include "print.h"
#include "spell.h"


void battle(player *player, enemy *enemy) {
  while (player->hp > 0 && enemy->hp > 0) {
    int count_of_attacks = character_attacks_count((character *) player);
    int count_of_spells = character_spells_count((character *) player);
    int count_of_choices = count_of_attacks + count_of_spells;

    action *a = prompt(player, enemy);

    /* if (choice > 0 && choice <= count_of_attacks) { */
    /*   int damage = attack_calculate_damage((character *) player, */
    /*                                        (character *) enemy, */
    /*                                        player->attacks[choice - 1]); */
    /*   print("%s attacked using %s!", player->name, player->attacks[choice - 1]->name); */
    /*   print("%s took %d damage!", enemy->name, damage); */
    /*   enemy->hp -= damage; */
    /* } else if (choice > count_of_attacks && choice <= count_of_choices) { */
    /*   int damage = attack_calculate_damage((character *) player, */
    /*                                        (character *) enemy, */
    /*                                        (attack *) player->spells[choice - count_of_attacks - 1]); */
    /*   print("%s attacked using %s!", */
    /*         player->name, */
    /*         player->spells[choice - count_of_attacks - 1]->name); */
    /*   print("%s took %d damage!", enemy->name, damage); */
    /*   enemy->hp -= damage; */
    /* } else { */
    /*   print("Invalid choice!"); */
    /* } */
  }

  if (player->hp > 0) {
    player->xp += enemy->xp_awarded;
    player->gold += enemy->gold_awarded;

    print("Player %s won!", player->name);
    print("Player %s gained %d XP!", player->name, enemy->xp_awarded);
    print("Player %s gained %d gold!", player->name, enemy->gold_awarded);
  } else {
    print("Player %s was defeated!", player->name);
  }
}

action *prompt(player *player, enemy *enemy) {
  print("%s: %d HP / %d MP",
        player->name,
        player->hp,
        player->mp);
  print("%s: %d HP / %d MP",
        enemy->name,
        enemy->hp,
        enemy->mp);

  int count_of_attacks = character_attacks_count((character *) player);

  for (int i = 0; player->attacks[i] != NULL; i++) {
    print("%d: %s (%d power)",
          i + 1, player->attacks[i]->name,
          player->attacks[i]->power);
  }

  for (int i = 0; player->spells[i] != NULL; i++) {
    print("%d: %s (%d power / %d cost)",
          count_of_attacks + i + 1,
          player->spells[i]->name,
          player->spells[i]->power,
          player->spells[i]->cost);
  }

  printf("> ");

  int input = getchar();
  if (input == EOF || input == '\n' || input == '\0') {
    putchar('\n');
    exit(0);
  }
  while(getchar() != '\n');

  /* return atoi((char *) &input); */
  return (action *) player->attacks[0];
}
