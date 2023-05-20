#ifndef OPP_H
#define OPP_H

#include <stdint.h>

#include "fallingpuyo.h"
#include "player.h"
#include "puyo.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_ROWS    12
#define BOARD_COLUMNS 6

#define BOARD_KILL_ROW    0
#define BOARD_KILL_COLUMN 2

#define PUYO_POOL_SIZE       256
#define NUM_OF_UPCOMING_PUYO 6

typedef struct original_puyo_puyo_game
{
    BoardPuyo board[BOARD_ROWS][BOARD_COLUMNS];
    PoolPuyo upcomingPuyo[NUM_OF_UPCOMING_PUYO];
    PoolPuyo colorSetThreePool[PUYO_POOL_SIZE];
    PoolPuyo colorSetFourPool[PUYO_POOL_SIZE];
    PoolPuyo colorSetFivePool[PUYO_POOL_SIZE];
    Player* currentStatus;
    uint32_t seed;
} OPPGame;

OPPGame* Initialize_OPPGame(uint32_t seed);
void OPP_reset_game(OPPGame* game);
void OPPGame_reset_pool(PoolPuyo* pool, ColorSet color_set);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* OPP_H */
