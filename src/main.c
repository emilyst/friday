#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "attack.h"
#include "battle.h"
#include "enemy.h"
#include "player.h"
#include "spell.h"


int main(void) {
  player est  = {
    .name     = "Est",
    .hp       = 100,
    .mp       = 50,
    .strength = 10,
    .skill    = 10,
    .defense  = 10,
    .spirit   = 10,
    .speed    = 10,
    .evasion  = 10,
    .luck     = 10,
    .accuracy = 10,
    .attacks = (attack*[]) {
      &((attack) {
        .name  = "Hack",
        .power = 1,
      }),
      &((attack) {
        .name  = "Slash",
        .power = 2,
      }),
      NULL,
    },
    .spells   = (spell*[]) {
      &((spell) {
        .name  = "Burn",
        .power = 5,
        .cost  = 2,
      }),
      &((spell) {
        .name  = "Freeze",
        .power = 5,
        .cost  = 2,
      }),
      NULL,
    },
    .xp = 0,
    .gold = 0,
  };

  enemy dragon = {
    .name      = "Dragon",
    .hp        = 100,
    .mp        = 50,
    .strength  = 10,
    .skill     = 10,
    .defense   = 10,
    .spirit    = 10,
    .speed     = 10,
    .evasion   = 50,
    .luck      = 10,
    .accuracy  = 10,
    .spells    = (spell*[]) {
      &((spell) {
        .name  = "Breath",
        .power = 10,
        .cost  = 2,
      }),
      NULL,
    },
    .attacks   = (attack*[]) {
      &((attack) {
        .name  = "Bite",
        .power = 5,
      }),
      &((attack) {
        .name  = "Claw",
        .power = 7,
      }),
      NULL,
    },
    .xp_awarded = 10,
    .gold_awarded = 20,
  };

  battle(&est, &dragon);
}
