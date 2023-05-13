#ifndef PUYO_HPP
#define PUYO_HPP

#include <cstdint>

typedef std::uint8_t puyo_t;

enum class ColorSet : std::uint8_t
{
    THREE = 3,
    FOUR = 4,
    FIVE = 5
};

enum class PoolPuyo : std::uint8_t
{
    RED,
    YELLOW,
    GREEN1,
    GREEN2,
    PURPLE,
    BLUE,
    OJAMA,
    BLOCK
};

#define PUYO_EMPTY  0
#define PUYO_RED    (8 << 4)
#define PUYO_YELLOW (9 << 4)
#define PUYO_GREEN1 (10 << 4)
#define PUYO_GREEN2 (11 << 4)
#define PUYO_PURPLE (12 << 4)
#define PUYO_BLUE   (13 << 4)
#define PUYO_OJAMA  (14 << 4)
#define PUYO_BLOCK  (15 << 4)

#endif /* PUYO_HPP */
