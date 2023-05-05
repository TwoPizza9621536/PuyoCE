/**
 * @file draw.c
 * @author Samuel Wu (twopizza9621536@gmail.com)
 * @brief
 * @version 0.1
 * @date 05/03/2023
 *
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 * SPDX-License-Identifier: MIT OR MPL-2.0
 *
 */

#include "draw.h"

#include <graphx.h>

#define BOARD_ROW_OFFSET    (PUYO_SIZE_32 - 1)
#define BOARD_COLUMN_OFFSET (PUYO_SIZE_64 - 1)

#define NEXT_PUYO_X_POS BOARD_COLUMN_OFFSET + BOARD_WIDTH + PUYO_SIZE_48
#define NEXT_PUYO_Y_POS BOARD_COLUMN_OFFSET

void draw_background(void)
{
    gfx_SetColor(255);

    gfx_FillRectangle(BOARD_COLUMN_OFFSET, BOARD_ROW_OFFSET, BOARD_WIDTH,
                      BOARD_HEIGHT);
    gfx_FillRectangle(NEXT_PUYO_X_POS, NEXT_PUYO_Y_POS, PUYO_SIZE_16,
                      PUYO_SIZE_32);
    gfx_FillRectangle(NEXT_PUYO_X_POS + PUYO_SIZE_16,
                      NEXT_PUYO_Y_POS + PUYO_SIZE_16, PUYO_SIZE_16,
                      PUYO_SIZE_32);
}

void draw_menu(void)
{
    gfx_SetColor(0);
    gfx_PrintStringXY("[2nd]", BOARD_COLUMN_OFFSET, BOARD_ROW_OFFSET);
}

void draw_puyo(void)
{
    for (size_t i = BOARD_KILL_ROW; i < BOARD_ROWS; i++)
    {
        for (size_t j = 0; j < BOARD_COLUMNS; j++)
        {
            gfx_Rectangle(j * PUYO_SIZE_16 + BOARD_ROW_OFFSET,
                          i * PUYO_SIZE_16 + BOARD_COLUMN_OFFSET, PUYO_SIZE_16,
                          PUYO_SIZE_16);
        }
    }
}
