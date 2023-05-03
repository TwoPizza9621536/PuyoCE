/*
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 *
 * SPDX-License-Identifier: MIT OR MPL-2.0
 */

#include "puyoce.h"

struct opp_game *create_opp_game(void)
{
    static struct opp_game game;
    return &game;
}

void reset_opp_game(struct opp_game *game)
{
    for (size_t i = 0; i < BOARD_ROWS; i++)
    {
        for (size_t j = 0; j < BOARD_COLUMNS; j++)
        {
            game->board[i][j] = 0;
        }
    }

    game->gameFlags = 0x00000000;
    game->score = 0;
}

void move_puyo(struct opp_game *game)
{
}

void end_game(struct opp_game *game)
{
}
