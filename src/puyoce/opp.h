#ifndef PUYOCE_OPP_H
#define PUYOCE_OPP_H

#include <stdbool.h>
#include <stdint.h>

#include "player.h"
#include "puyo.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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
    ColorSet colorSet;
    uint32_t seed;
    uint8_t currentRound;
} OPPGame;

OPPGame* Initialize_OPPGame(const uint32_t seed);
void OPPGame_reset(OPPGame* const game, const ColorSet color_set);
void OPPGame_reset_pool(PoolPuyo* const pool, const ColorSet color_set);
void OPPGame_set_board(OPPGame* const game, const BoardPuyo puyo);
PoolPuyo* OPPGame_select_pool(OPPGame* const game, const ColorSet color_set);
bool OPPGame_spawn_puyo(OPPGame* const game);

#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* PUYOCE_OPP_H */
