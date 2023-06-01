#include <stdint.h>

#include "opp.h"
#include "player.h"
#include "puyo.h"

Player* Initialize_Player(const uint32_t id, PoolPuyo* const upcoming_puyo)
{
    static Player player;

    player.id = id;

    player.selectedPuyo = Initialize_FallingPuyo(id);
    player.upcomingPuyo = upcoming_puyo;

    return &player;
}

void Player_reset_status(Player* const player)
{
    player->chainLength = 0;
    player->chainScore = 0;
    player->chianMultiplier = 0;

    FallingPuyo_reset(player->selectedPuyo);
}

void Player_hold_puyo(Player* const status)
{
    status->selectedPuyo->color = status->upcomingPuyo[0];
    status->selectedPuyo->xPosition = BOARD_KILL_COLUMN;
    status->selectedPuyo->yPosition = 0;
    status->selectedPuyo->rotation = PUYO_ROTATION_TOP;

    status->selectedPuyo->neighboringPuyo->color = status->upcomingPuyo[1];
    status->selectedPuyo->neighboringPuyo->xPosition = BOARD_KILL_COLUMN;
    status->selectedPuyo->neighboringPuyo->yPosition = 1;
    status->selectedPuyo->rotation = PUYO_ROTATION_BOTTOM;
}

void Player_move_puyo(Player* const status, const uint8_t movement)
{
    switch (movement)
    {
    case MOVEMENT_DOWN:

        break;

    default:
        break;
    }
}
