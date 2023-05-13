#include <cstdint>
#include <cstdlib>

#include "opp.hpp"
#include "puyo.hpp"

OppGame::OppGame()
{
    resetGame();
}

OppGame::~OppGame()
{
}

void OppGame::resetGame()
{
    resetAndRandomizePools(ColorSet::THREE);
    resetAndRandomizePools(ColorSet::FOUR);
    resetAndRandomizePools(ColorSet::FIVE);

    for (int i = 0; i < 4; i++)
    {
        m_colorSetFourPool[i] = m_colorSetThreePool[i];
        m_colorSetFivePool[i] = m_colorSetThreePool[i];
    }

    for (int i = 4; i < 8; i++)
    {
        m_colorSetFivePool[i] = m_colorSetFourPool[i];
    }
}

void OppGame::resetAndRandomizePools(ColorSet colorSet)
{
    int dividend;
    PoolPuyo* pool;

    switch (colorSet)
    {
    case ColorSet::THREE:
        pool = m_colorSetThreePool;
        dividend = 3;
        break;

    case ColorSet::FOUR:
        pool = m_colorSetFourPool;
        dividend = 4;
        break;

    case ColorSet::FIVE:
        pool = m_colorSetFivePool;
        dividend = 5;
        break;

    default:
        return;
    }

    for (int i = 0; i < PUYO_POOL_SIZE; i++)
    {
        switch (i % dividend)
        {
        case 0:
            pool[i] = PoolPuyo::RED;
            break;

        case 1:
            pool[i] = PoolPuyo::YELLOW;
            break;

        case 2:
            pool[i] = PoolPuyo::GREEN2;
            break;

        case 3:
            pool[i] = PoolPuyo::BLUE;
            break;

        case 4:
            pool[i] = PoolPuyo::PURPLE;
            break;
        }
    }

    for (int i = PUYO_POOL_SIZE - 1; i >= 0; i--)
    {
        int randPuyoIndex = rand() % 256;
        PoolPuyo temp = pool[i];

        pool[i] = pool[randPuyoIndex];
        pool[randPuyoIndex] = temp;
    }
}
