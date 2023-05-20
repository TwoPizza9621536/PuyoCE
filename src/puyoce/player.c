#include "player.h"
#include "opp.h"
#include "puyo.h"

Player* Initialize_Player(const uint32_t id, PoolPuyo* upcoming_puyo)
{
    static Player player;

    player.id = id;

    player.selectedPuyo = Initialize_FallingPuyo(id);
    player.upcomingPuyo = upcoming_puyo;

    return &player;
}

void Player_reset_status(Player* player)
{
    player->chainLength = 0;
    player->chainScore = 0;
    player->chianMultiplier = 0;

    FallingPuyo_reset(player->selectedPuyo);
}

void Player_hold_puyo(Player* player_status)
{
    player_status->selectedPuyo->color = player_status->upcomingPuyo[0];
    player_status->selectedPuyo->xPosition = BOARD_KILL_COLUMN;
    player_status->selectedPuyo->yPosition = 0;
    player_status->selectedPuyo->rotation = PUYO_ROTATION_TOP;

    player_status->selectedPuyo->neighboringPuyo->color =
        player_status->upcomingPuyo[1];
    player_status->selectedPuyo->neighboringPuyo->xPosition = BOARD_KILL_COLUMN;
    player_status->selectedPuyo->neighboringPuyo->yPosition = 1;
    player_status->selectedPuyo->rotation = PUYO_ROTATION_BOTTOM;
}
