#include <stddef.h>

#include "print.h"
#include "player.h"


void player_print_attributes(const player *player) {
  character_print_attributes((const character *) player);
  print_attribute("XP", player->xp);
}
