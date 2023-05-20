#include "puyo.h"

FallingPuyo* Initialize_FallingPuyo(const uint8_t player_id)
{
    static FallingPuyo main_puyo;
    static FallingPuyo sub_puyo;

    main_puyo.playerID = player_id;
    main_puyo.neighboringPuyo = &sub_puyo;

    sub_puyo.playerID = player_id;
    return &main_puyo;
}

void FallingPuyo_reset(FallingPuyo* puyo)
{
    puyo->color = POOL_PUYO_RED;
    puyo->status = 0;
    puyo->rotation = PUYO_ROTATION_TOP;
    puyo->rotationCount = 0;
    puyo->xPosition = 0;
    puyo->yPosition = 0;

    puyo->neighboringPuyo->color = POOL_PUYO_RED;
    puyo->neighboringPuyo->status = 0;
    puyo->neighboringPuyo->rotation = PUYO_ROTATION_TOP;
    puyo->neighboringPuyo->rotationCount = 0;
    puyo->neighboringPuyo->xPosition = 0;
    puyo->neighboringPuyo->yPosition = 0;
}
