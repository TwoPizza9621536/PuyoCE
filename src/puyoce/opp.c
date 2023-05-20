#include <sys/util.h>

#include "opp.h"

#include "fallingpuyo.h"
#include "player.h"

#define PLAYER_ID 1

OPPGame* Initialize_OPPGame(uint32_t seed)
{
    static OPPGame game;

    game.currentStatus = Initialize_OPPGame(PLAYER_ID);
    game.seed = seed;

    srandom(seed);

    return &game;
}

void OPP_reset_game(OPPGame* game)
{
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
            game->board[i][j] = BOARD_PUYO_EMPTY;
        }
    }

    OPPGame_reset_pool(game->colorSetThreePool, COLOR_SET_THREE);

    for (int i = 0; i < 4; i++)
    {
        game->colorSetFourPool[i] = game->colorSetThreePool[i];
        game->colorSetFivePool[i] = game->colorSetThreePool[i];
    }

    for (int i = 4; i < 8; i++)
    {
        game->colorSetFivePool[i] = game->colorSetFourPool[i];
    }

    Player_reset_status(game->currentStatus);
}

void OPPGame_reset_pool(PoolPuyo* pool, ColorSet color_set)
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
