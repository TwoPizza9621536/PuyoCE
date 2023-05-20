#ifndef FALLING_PUYO_H
#define FALLING_PUYO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct falling_puyo
{
    uint8_t playerID;
    uint8_t color;
    uint8_t status;
    uint16_t xPosition;
    uint16_t yPosition;
    uint8_t rotation;
    struct falling_puyo* danglingPuyo;
} FallingPuyo;

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* FALLING_PUYO_H */
