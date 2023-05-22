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

    if (PUYOGFX_init() == 0)
    {
        os_ClrHome();

        os_SetCursorPos(0, 2);
        os_SetDrawBGColor(OS_COLOR_BLACK);
        os_SetDrawFGColor(OS_COLOR_WHITE);
        os_PutStrLine("ERROR: Missing Library");

        os_SetCursorPos(2, 0);
        os_SetDrawBGColor(OS_COLOR_WHITE);
        os_SetDrawFGColor(OS_COLOR_BLACK);
        os_PutStrLine("Library Name: PUYOGFX");
        os_SetCursorPos(4, 0);
        os_PutStrLine("Did you uploaded");
        os_NewLine();
        os_PutStrLine("PUYOGFX.8xv along with");
        os_NewLine();
        os_PutStrLine("PUYOCE.8xp?");

        while (!os_GetCSC()) continue;

        return 1;
    }

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    draw_background();
    gfx_SwapDraw();

    do {
        kb_Scan();

        gfx_BlitScreen();
        gfx_TransparentSprite_NoClip(menu, MENU_OFFSET, MENU_OFFSET);

        isClear = kb_Data[6] == kb_Clear;
        is2nd = kb_Data[1] == kb_2nd;

        if (isClear && !prevKey) break;
        if (is2nd && !prevKey) main_game_routine();

        prevKey = isClear || is2nd;
        gfx_SwapDraw();
    }
    while (true);

    gfx_End();

    return 0;
}
