#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

#include "fallingpuyo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct player
{
    uint8_t id;
    uint8_t chainLength;
    uint32_t score;
    uint32_t chainScore;
    uint16_t chianMultiplier;
    FallingPuyo* selected_puyo;
} Player;

Player* Initialize_Player(const uint32_t id);
void Player_reset_status(Player* player);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* PLAYER_H */
