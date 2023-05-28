#include <graphx.h>

#include "gfx/puyogfx.h"

#include "draw.h"
#include "puyoce/puyoce.h"

void draw_background(void)
{
    gfx_ZeroScreen();
    gfx_SetColor(2);

    gfx_FillRectangle(BOARD_OFFSET, BOARD_OFFSET, BOARD_WIDTH, BOARD_HEIGHT);

    /* Draw next puyo slots */
    gfx_FillRectangle(NEXT1_X_POS, NEXT1_Y_POS, NEXT_WIDTH, NEXT_HEIGHT);
    gfx_FillRectangle(NEXT2_X_POS, NEXT2_Y_POS, NEXT_WIDTH, NEXT_HEIGHT);
    gfx_TransparentSprite_NoClip(text_next, NEXT_TEXT_X_POS, BOARD_OFFSET);

    /* Draw score and puyo counters */
    gfx_FillRectangle(COUNT_X_POS, COUNT_Y_POS, COUNT_WIDTH, COUNT_HEIGHT);
    gfx_FillRectangle(COUNT_X_POS, SCORE_Y_POS, COUNT_WIDTH, COUNT_HEIGHT);
    gfx_TransparentSprite_NoClip(text_puyo_popped, POPPED_X_POS, COUNT_Y_POS);
    gfx_TransparentSprite_NoClip(text_score, SCORE_X_POS, SCORE_Y_POS);
}

void draw_menu(void)
{
    draw_background();

    gfx_TransparentSprite_NoClip(text_high, HIGH_X_POS, SCORE_Y_POS);
    gfx_TransparentSprite_NoClip(text_menu, MENU_OFFSET, MENU_OFFSET);
    gfx_SwapDraw();
}

void draw_puyo(void)
{
    for (int i = BOARD_KILL_ROW; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
        }
    }
}

void draw_holding_puyo(void)
{
}
