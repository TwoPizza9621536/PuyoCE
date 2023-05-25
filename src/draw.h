#ifndef DRAW_H
#define DRAW_H

#define SPRITE_8   8
#define SPRITE_16  16
#define SPRITE_24  24
#define SPRITE_32  32
#define SPRITE_48  48
#define SPRITE_64  64
#define SPRITE_96  96
#define SPRITE_128 128
#define SPRITE_256 256

#define BOARD_WIDTH  (BOARD_COLUMNS * SPRITE_16)
#define BOARD_HEIGHT (BOARD_ROWS * SPRITE_16)
#define BOARD_OFFSET (SPRITE_24 - 1)

#define MENU_OFFSET (BOARD_OFFSET + SPRITE_8)

#define NEXT1_X_POS (BOARD_OFFSET + BOARD_WIDTH + SPRITE_24)
#define NEXT1_Y_POS (BOARD_OFFSET + SPRITE_16)
#define NEXT2_X_POS (NEXT1_X_POS + SPRITE_24)
#define NEXT2_Y_POS (NEXT1_Y_POS + SPRITE_8)

#define COUNT_X_POS NEXT1_X_POS
#define COUNT_Y_POS SPRITE_128

void draw_background(void);

void draw_menu(void);

void draw_puyo(void);

#endif /* DRAW_H */
