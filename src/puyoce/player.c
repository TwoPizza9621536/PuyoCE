#include "player.h"

Player* Initialize_Player(const uint32_t id)
{
    static Player player;
    static FallingPuyo main_puyo;
    static FallingPuyo sub_puyo;

    player.id = id;
    player.selected_puyo = &main_puyo;
    main_puyo.danglingPuyo = &sub_puyo;

    return &player;
}

void Player_reset_status(Player* player)
{
    player->chainLength = 0;
    player->chainScore = 0;
    player->chianMultiplier = 0;
}
