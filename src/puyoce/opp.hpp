#ifndef OPP_HPP
#define OPP_HPP

#include "puyo.hpp"

constexpr int BOARD_ROWS = 12;
constexpr int BOARD_COLUMNS = 6;

constexpr int BOARD_KILL_ROW = 0;
constexpr int BOARD_KILL_COLUMN = 2;

constexpr int PUYO_POOL_SIZE = 256;

class OppGame
{
private:
    puyo_t m_board[BOARD_ROWS][BOARD_COLUMNS];
    PoolPuyo m_colorSetThreePool[PUYO_POOL_SIZE];
    PoolPuyo m_colorSetFourPool[PUYO_POOL_SIZE];
    PoolPuyo m_colorSetFivePool[PUYO_POOL_SIZE];

public:
    OppGame();
    ~OppGame();

private:
    void resetGame();
    void resetAndRandomizePools(ColorSet colorSet);
};

#endif /* OPP_HPP */
