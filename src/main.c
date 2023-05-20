#include <graphx.h>
#include <keypadc.h>

#include <sys/rtc.h>

#include "puyoce/puyoce.h"

#include "draw.h"
#include "gfx/gfx.h"

bool main_game_routine(OppGame& game)
{
    kb_key_t key;

    game.resetGame();

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
    }
    while (true);
}

int main()
{
    bool is2nd;
    bool isClear;
    bool prevKey = false;

    static OppGame game {rtc_Time()};

    gfx_Begin();

    initialize_graphics();

    draw_background();

    gfx_Sprite_NoClip(menu, MENU_OFFSET, MENU_OFFSET);

    gfx_SwapDraw();

    do
    {
        kb_Scan();

        isClear = kb_Data[6] == kb_Clear;
        is2nd = kb_Data[1] == kb_2nd;

        if (isClear && !prevKey)
        {
            break;
        }

        if (is2nd && !prevKey)
        {
            main_game_routine(game);
        }

        prevKey = isClear || is2nd;
    }
    while (true);

    gfx_End();

    return 0;
}
