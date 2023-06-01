#include <stdbool.h>
#include <stdint.h>
#include <sys/util.h>

#include "opp.h"
#include "player.h"
#include "puyo.h"

#define PLAYER_ID 1

OPPGame* Initialize_OPPGame(const uint32_t seed)
{
    static OPPGame game;

    game.currentStatus = Initialize_Player(PLAYER_ID, game.upcomingPuyo);
    game.seed = seed;

    srandom(seed);

    return &game;
}

void OPPGame_reset(OPPGame* const game, const ColorSet color_set)
{
    const PoolPuyo* const pool = OPPGame_select_pool(game, color_set);
    game->colorSet = color_set;

    OPPGame_set_board(game, BOARD_PUYO_EMPTY);

    OPPGame_reset_pool(game->colorSetThreePool, COLOR_SET_THREE);
    OPPGame_reset_pool(game->colorSetFourPool, COLOR_SET_FOUR);
    OPPGame_reset_pool(game->colorSetFivePool, COLOR_SET_FIVE);

    for (int i = 0; i < 4; i++)
    {
        game->colorSetFourPool[i] = game->colorSetThreePool[i];
        game->colorSetFivePool[i] = game->colorSetThreePool[i];
    }

    for (int i = 4; i < 8; i++)
    {
        game->colorSetFivePool[i] = game->colorSetFourPool[i];
    }

    for (int i = 0; i < NUM_OF_UPCOMING_PUYO; i++)
    {
        game->upcomingPuyo[i] = pool[i];
    }

    Player_reset_status(game->currentStatus);

    game->currentRound++;
}

void OPPGame_reset_pool(PoolPuyo* const pool, const ColorSet color_set)
{
    for (int i = 0; i < PUYO_POOL_SIZE; i++)
    {
        switch (i % color_set)
        {
        case 0:
            pool[i] = POOL_PUYO_RED;
            break;

        case 1:
            pool[i] = POOL_PUYO_YELLOW;
            break;

        case 2:
            pool[i] = POOL_PUYO_GREEN2;
            break;

        case 3:
            pool[i] = POOL_PUYO_BLUE;
            break;

        case 4:
            pool[i] = POOL_PUYO_PURPLE;
            break;
        }
    }

    for (int i = PUYO_POOL_SIZE - 1; i >= 0; i--)
    {
        int randPuyoIndex = random() % 256;
        PoolPuyo temp = pool[i];

        pool[i] = pool[randPuyoIndex];
        pool[randPuyoIndex] = temp;
    }
}

PoolPuyo* OPPGame_select_pool(OPPGame* const game, const ColorSet color_set)
{
    switch (color_set)
    {
    case COLOR_SET_THREE:
        return game->colorSetThreePool;

    case COLOR_SET_FOUR:
        return game->colorSetFourPool;

    case COLOR_SET_FIVE:
        return game->colorSetFivePool;

    default:
        return game->colorSetFourPool;
    }
}

void OPPGame_set_board(OPPGame* const game, const BoardPuyo puyo)
{
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
            game->board[i][j] = puyo;
        }
    }
}

bool OPPGame_spawn_puyo(OPPGame* const game)
{
    static int poolIndex = 6;
    const PoolPuyo* const pool = OPPGame_select_pool(game, game->colorSet);

    if (game->board[3][0] != BOARD_PUYO_EMPTY)
    {
        return false;
    }

    Player_hold_puyo(game->currentStatus);

    for (int i = 2; i < NUM_OF_UPCOMING_PUYO; i += 2)
    {
        game->upcomingPuyo[i - 2] = game->upcomingPuyo[i];
        game->upcomingPuyo[i - 1] = game->upcomingPuyo[i + 1];
    }

    for (int i = 4; i < NUM_OF_UPCOMING_PUYO; i++)
    {
        game->upcomingPuyo[i] = pool[poolIndex];
        poolIndex++;
    }

    return true;
}
