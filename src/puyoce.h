/*
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 *
 * SPDX-License-Identifier: MIT OR MPL-2.0
 */

#ifndef PUYOCE_H
#define PUYOCE_H

#include <stdint.h>

#define PUYO_SIZE_8 8
#define PUYO_SIZE_16 16
#define PUYO_SIZE_32 32
#define PUYO_SIZE_48 48
#define PUYO_SIZE_64 64
#define PUYO_SIZE_96 96
#define PUYO_SIZE_128 128
#define PUYO_SIZE_256 256

#define BOARD_ROWS 13
#define BOARD_COLUMNS 6

#define BOARD_KILL_ROW 1
#define BOARD_KILL_COLUMN 2

struct opp_game
{
    uint32_t score;
    uint8_t gameFlags;
    uint8_t nextQueue[64];
    uint8_t board[BOARD_ROWS][BOARD_COLUMNS];
};

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    struct opp_game *create_opp_game(void);

    void reset_opp_game(struct opp_game *game);

    void move_puyo(struct opp_game *game);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* PUYOCE_H */
