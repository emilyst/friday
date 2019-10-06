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
    print("%s: %d", player->name, player->hp);
    print("%s: %d", enemy->name,  enemy->hp);

    int count_of_attacks;
    for (int i = 0; player->attacks[i] != NULL; count_of_attacks = ++i) {
      print("%d: %s (%d power)",
            i + 1, player->attacks[i]->name,
            player->attacks[i]->power);
    }

    int count_of_spells;
    for (int i = 0; player->spells[i] != NULL; count_of_spells = ++i) {
      print("%d: %s (%d power / %d cost)",
            count_of_attacks + i + 1,
            player->spells[i]->name,
            player->spells[i]->power,
            player->spells[i]->cost);
    }

    int choice = prompt();

    if (choice > 0 && choice <= count_of_attacks) {
      int damage = attack_calculate_damage((character *) player,
                                           (character *) enemy,
                                           player->attacks[choice - 1]);
      print("%s attacked using %s!", player->name, player->attacks[choice - 1]->name);
      print("%s took %d damage!", enemy->name, damage);
      enemy->hp -= damage;
    } else if (choice > count_of_attacks && choice <= count_of_spells + count_of_attacks) {
      int damage = attack_calculate_damage((character *) player,
                                           (character *) enemy,
                                           (attack *) player->spells[choice - count_of_attacks - 1]);
      print("%s attacked using %s!",
            player->name,
            player->spells[choice - count_of_attacks - 1]->name);
      print("%s took %d damage!", enemy->name, damage);
      enemy->hp -= damage;
    } else {
      print("Invalid choice!");
    }
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

int prompt() {
  printf("> ");

  char buffer[1];
  buffer[0] = getchar();
  while(getchar() != '\n');
  return atoi(buffer);
}
