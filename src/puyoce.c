/**
 * @file puyoce.c
 * @author Samuel Wu (twopizza9621536@gmail.com)
 * @brief
 * @version 0.1
 * @date 05/03/2023
 *
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 * SPDX-License-Identifier: MIT OR MPL-2.0
 *
 */

#include "puyoce.h"

OppGame *create_opp_game(void)
{
    static struct opp_game game;
    return &game;
}

void reset_opp_game(OppGame *game)
{
    for (size_t i = 0; i < BOARD_ROWS; i++)
    {
        for (size_t j = 0; j < BOARD_COLUMNS; j++)
        {
            game->board [i][j] = 0;
        }
    }

    game->flags = 0;
    game->score = 0;
}

void change_opp_game(OppGame *game)
{
}

void end_game(OppGame *game)
{
}
