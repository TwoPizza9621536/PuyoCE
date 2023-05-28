#ifndef PUYOCE_PUYO_H
#define PUYOCE_PUYO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef uint8_t BoardPuyo;
typedef uint8_t PoolPuyo;
typedef uint8_t ColorSet;

typedef struct falling_puyo
{
    uint8_t playerID;
    uint8_t color;
    uint8_t status;
    uint8_t rotation;
    uint8_t rotationCount;
    uint16_t xPosition;
    uint16_t yPosition;
    struct falling_puyo* neighboringPuyo;
} FallingPuyo;

FallingPuyo* Initialize_FallingPuyo(const uint8_t player_id);
void FallingPuyo_reset(FallingPuyo* const puyo);

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

#define PUYO_STATUS_MAIN_BLOCKED (1 << 0)
#define PUYO_STATUS_SUB_BLOCKED  (1 << 1)
#define PUYO_STATUS_LOCKED       (1 << 2)
#define PUYO_STATUS_FALL         (1 << 3)

#define PUYO_ROTATION_TOP    0
#define PUYO_ROTATION_RIGHT  1
#define PUYO_ROTATION_BOTTOM 2
#define PUYO_ROTATION_LEFT   3

#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* PUYOCE_PUYO_H */
