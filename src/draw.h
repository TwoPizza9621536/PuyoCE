/**
 * @file draw.h
 * @author Samuel Wu (twopizza9621536@gmail.com)
 * @brief
 * @version 0.1
 * @date 05/03/2023
 *
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 * SPDX-License-Identifier: MIT OR MPL-2.0
 *
 */

#ifndef DRAW_H
#define DRAW_H

#include "puyoce.h"

#define PUYO_SIZE_8   8
#define PUYO_SIZE_16  16
#define PUYO_SIZE_32  32
#define PUYO_SIZE_48  48
#define PUYO_SIZE_64  64
#define PUYO_SIZE_96  96
#define PUYO_SIZE_128 128
#define PUYO_SIZE_256 256

#define BOARD_WIDTH  (BOARD_COLUMNS * PUYO_SIZE_16)
#define BOARD_HEIGHT ((BOARD_ROWS - 1) * PUYO_SIZE_16)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void draw_background(void);

void draw_menu(void);

void draw_puyo(void);

#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* DRAW_H */
