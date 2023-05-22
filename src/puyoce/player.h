#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

#include "puyo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t MovementCodes;

typedef struct player
{
    uint8_t id;
    uint8_t chainLength;
    uint32_t score;
    uint32_t chainScore;
    uint16_t chianMultiplier;
    FallingPuyo* selectedPuyo;
    PoolPuyo* upcomingPuyo;
} Player;

Player* Initialize_Player(const uint32_t id, PoolPuyo* upcoming_puyo);
void Player_reset_status(Player* player);
void Player_hold_puyo(Player* status);
void Player_move_puyo(Player* status, const uint8_t movement);

#define MOVEMENT_DOWN         (1 << 0)
#define MOVEMENT_LEFT         (1 << 1)
#define MOVEMENT_RIGHT        (1 << 2)
#define MOVEMENT_ROTATE_RIGHT (1 << 3)
#define MOVEMENT_ROTATE_LEFT  (1 << 4)

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* PLAYER_H */
