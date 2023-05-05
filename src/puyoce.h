/**
 * @file puyoce.h
 * @author Samuel Wu (twopizza9621536@gmail.com)
 * @brief
 * @version 0.1
 * @date 05/03/2023
 *
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 * SPDX-License-Identifier: MIT OR MPL-2.0
 *
 */

#ifndef PUYOCE_H
#define PUYOCE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct opp_game OppGame;
typedef uint8_t game_flags_t;

OppGame* create_opp_game(void);

void reset_opp_game(OppGame* game);

void change_opp_game(OppGame* game);

#define BOARD_ROWS    13
#define BOARD_COLUMNS 6

#define BOARD_KILL_ROW    1
#define BOARD_KILL_COLUMN 2

#define TEMP_QUEUE_NUMBER 64

#define GAME_END_FLAG       (1 << 0)
#define GAME_ALL_CLEAR_FLAG (1 << 1)

struct opp_game {
    game_flags_t flags;
    uint32_t score;
    uint8_t nextQueue [TEMP_QUEUE_NUMBER];
    uint8_t board [BOARD_ROWS][BOARD_COLUMNS];
};

#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* PUYOCE_H */
