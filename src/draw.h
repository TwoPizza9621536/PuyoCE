/*
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 *
 * SPDX-License-Identifier: MIT OR MPL-2.0
 */

#ifndef DRAW_H
#define DRAW_H

#include <graphx.h>

#include "puyoce.h"

#define BOARD_WIDTH (BOARD_COLUMNS * PUYO_SIZE_16)
#define BOARD_HEIGHT ((BOARD_ROWS - 1) * PUYO_SIZE_16)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    void draw_background(void);

    void draw_puyo(void);

    void draw_menu(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* DRAW_H */
