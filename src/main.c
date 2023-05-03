/*
 * SPDX-FileCopyrightText: 2023 Samuel Wu
 *
 * SPDX-License-Identifier: MIT OR MPL-2.0
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include <graphx.h>
#include <keypadc.h>
#include <debug.h>

#include "puyoce.h"
#include "draw.h"

void initialize_graphics(void)
{
    gfx_SetDrawBuffer();
    gfx_FillScreen(0);
}

bool main_game_routine(struct opp_game *game)
{
    static int firstPuyoXPos = BOARD_KILL_ROW;
    static int firstPuyoYPos = BOARD_KILL_COLUMN;
    kb_key_t key;

    reset_opp_game(game);
    draw_background();

    do
    {
        kb_Scan();

        if (kb_Data[6] == kb_Clear)
        {
            return false;
        }

        key = kb_Data[7];
        switch (key)
        {
        case kb_Up:
        case kb_2nd:
            firstPuyoYPos--;
            break;

        case kb_Alpha:
            break;

        case kb_Down:
            firstPuyoYPos++;
            break;

        case kb_Left:
            firstPuyoXPos--;
            break;

        case kb_Right:
            firstPuyoXPos++;
            break;

        default:
            break;
        }

        // if (firstPuyoYPos < BOARD_ROW_OFFSET) {
        //     firstPuyoYPos = BOARD_ROW_OFFSET;
        // }
        // if (firstPuyoYPos > BOARD_ROWS) {
        //     firstPuyoYPos = BOARD_ROWS;
        // }
        // if (firstPuyoXPos < BOARD_COLUMN_OFFSET) {
        //     firstPuyoXPos = BOARD_COLUMN_OFFSET;
        // }
        // if (firstPuyoXPos > BOARD_COLUMNS) {
        //     firstPuyoXPos = BOARD_COLUMNS;
        // }
        // draw_puyo();
        gfx_SwapDraw();
    } while (true);
}

int main(void)
{
    bool is2nd;
    bool isClear;
    bool prevkey = false;

    struct opp_game *game = create_opp_game();

    gfx_Begin();

    initialize_graphics();

    draw_background();
    draw_menu();
    gfx_BlitScreen();

    do
    {
        kb_Scan();

        isClear = kb_Data[6] == kb_Clear;
        is2nd = kb_Data[1] == kb_2nd;

        if (isClear && !prevkey)
        {
            break;
        }

        if (is2nd && !prevkey)
        {
            main_game_routine(game);
        }

        prevkey = isClear || is2nd;
    } while (true);

    gfx_End();

    return 0;
}
