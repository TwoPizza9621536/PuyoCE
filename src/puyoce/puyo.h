#ifndef PUYO_H
#define PUYO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t BoardPuyo;
typedef uint8_t PoolPuyo;
typedef uint8_t ColorSet;

#define POOL_PUYO_RED    0
#define POOL_PUYO_YELLOW 1
#define POOL_PUYO_GREEN1 2
#define POOL_PUYO_GREEN2 3
#define POOL_PUYO_PURPLE 4
#define POOL_PUYO_BLUE   5
#define POOL_PUYO_OJAMA  6
#define POOL_PUYO_BLOCK  7

#define BOARD_PUYO_EMPTY  0
#define BOARD_PUYO_RED    (8 << 4)
#define BOARD_PUYO_YELLOW (9 << 4)
#define BOARD_PUYO_GREEN1 (10 << 4)
#define BOARD_PUYO_GREEN2 (11 << 4)
#define BOARD_PUYO_PURPLE (12 << 4)
#define BOARD_PUYO_BLUE   (13 << 4)
#define BOARD_PUYO_OJAMA  (14 << 4)
#define BOARD_PUYO_BLOCK  (15 << 4)

#define COLOR_SET_THREE 3
#define COLOR_SET_FOUR  4
#define COLOR_SET_FIVE  5

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* PUYO_H */
