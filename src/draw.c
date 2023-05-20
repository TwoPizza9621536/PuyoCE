#include <graphx.h>

#include "gfx/gfx.h"

#include "draw.h"
#include "puyoce/puyoce.h"

void draw_background(void)
{
    gfx_SetColor(0);
    gfx_FillRectangle(BOARD_OFFSET, BOARD_OFFSET, BOARD_WIDTH, BOARD_HEIGHT);
    gfx_FillRectangle(NEXT1_X_POS, NEXT1_Y_POS, SPRITE_32, SPRITE_48);
    gfx_FillRectangle(NEXT2_X_POS, NEXT2_Y_POS, SPRITE_32, SPRITE_48);
    gfx_FillRectangle(COUNT_X_POS, COUNT_Y_POS, SPRITE_96, SPRITE_16);
    gfx_FillRectangle(COUNT_X_POS, COUNT_Y_POS + SPRITE_48, SPRITE_96,
                      SPRITE_16);
}

void draw_puyo(void)
{
    for (int i = BOARD_KILL_ROW; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
            gfx_Rectangle(j * SPRITE_16 + BOARD_OFFSET,
                          i * SPRITE_16 + BOARD_OFFSET, SPRITE_16, SPRITE_16);
        }
    }
}

void initialize_graphics(void)
{
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_FillScreen(1);
}
