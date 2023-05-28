#include <graphx.h>
#include <keypadc.h>

#include <sys/rtc.h>
#include <ti/getcsc.h>
#include <ti/screen.h>

#include "puyoce/puyoce.h"

#include "draw.h"
#include "game.h"
#include "gfx/puyogfx.h"

int main(void)
{
    bool is2nd;
    bool isClear;
    bool prevKey = false;
    // TODO: Select color set in menu
    OPPGame* game = Initialize_OPPGame(0);

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    draw_menu();

    while (true)
    {
        kb_Scan();

        isClear = kb_Data[6] == kb_Clear;
        is2nd = kb_Data[1] == kb_2nd;

        if (isClear && !prevKey) break;
        if (is2nd && !prevKey)
        {
            main_game_routine();
            draw_menu();
        }

        prevKey = isClear || is2nd;
    }

    gfx_End();

    return 0;
}
