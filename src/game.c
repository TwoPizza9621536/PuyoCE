#include <stdbool.h>

#include <graphx.h>
#include <keypadc.h>

#include "draw.h"
#include "game.h"

void main_game_routine(void)
{
    draw_background();
    gfx_SwapDraw();

    while (main_logic_routine())
    {
        gfx_BlitScreen();

        gfx_SwapDraw();
    }
}

bool main_logic_routine(void)
{
    kb_key_t key;

    kb_Scan();

    if (kb_Data[6] == kb_Clear) return false;

    key = kb_Data[7];
    switch (key)
    {
    case kb_Up:
    case kb_2nd:
        break;

    case kb_Alpha:
        break;

    case kb_Down:
        break;

    case kb_Left:
        break;

    case kb_Right:
        break;

    default:
        break;
    }

    return true;
}
