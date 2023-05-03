# Puyo Puyo Implementation

> Disclaimer: This is **NOT** Compile's or SEGA's official implementation for
> Puyo Puyo. This is just a document that list how I think Puyo Puyo is created,
> designed and implemented. **This implementation is UNOFFICIAL.**

## The Main Game

Puyo Puyo is a puzzle game where you need to connect puyo together orthogonality
(up, down, left, right) to gain points, and chain them like domino to gain more
points. This is more about the technical details of Puyo Puyo to implement it.

## Board and Play Area

The play area is a 13 by 6 grid. The topmost row (0th) is a hidden row and puyo
does connect with each other. Only one puyo is inside of the squares and puyo
must not be outside of the play area.

The 2nd column of the 1st row is the kill area and the kill area may extend
to the 3rd column of the 1st row for different sets of rules. If a puyo reaches
the kill area, and that puyo does not disappear, then the player loses the game.

The kill check is implement after any other checks on the board but before
next pair puyo spawns on to the board. We just need to make sure the player
losses before getting puyo if there are no chains to be made.

### Representation

The play area will be a 2D array statically allocated to memory. The play area
might be apart of a structure that includes the score, end game flag, next puyo
queue, etc. We are passing this data around as a pointer so other functions
reference our statically allocated instead of copying our play area into the
stack.

```c
typedef struct {
    uint32_t score;
    uint8_t gameFlags;
    uint8_t nextQueue[NUM_OF_PUYO_GOING_TO_BE_IN_QUEUE];
    uint8_t board[13][6];
} INSERT_NAME_FOR_STRUCT;
```

Initialization and resetting of the board requires different functions to
support different rules and modes. There might be a need for more or bigger
boards for game modes as we need to save a board for fever equivalents, but this
not a concern yet as this port will be supporting Original Puyo Puyo as a single
player game.

## Puyo

Puyo is represented by 16 bits due to memory constraints of the TI-84 Plus CE.
8 bits is very limiting for types and attribution but we can assign ids. 16
bits is most likely to be possible but it might waste space. Both can divided
into different sections starting from the least significant bit to the most
significant bit to maintain 8 bit compatibility / fallback if we chose to use
to use 8 bits.

There are many different ways to represent puyo by using ids with an utf-8
style assignment or flags.

There are 13 types of puyo throughout the series.[^1] But puyo can be frozen
and we need might need to add more puyo, color, power-ups, and generally this
need to be expandable.

Both ids and flags can also be used to draw the puyo based on if they are
connected but some assets does not have sprites for connected puyo like
skins for retro style, block, letters, etc. But if we do this, it is best to
check the board twice for [game routines](#routines-checks-and-timers) and
graphics if we want to separate the graphics.

## Routines, Checks and Timers

We need to following checks for OPP: Bounds, Fall, Pop, Kill.

Bounds check is easy, make sure the puyo are within this range:
`0 <= x < 13` and `0 <= y < 6`. This is inside of the movement routine
for obvious reasons.

### Controls

Controls from Tetric A, should we follow official controls for rotation or
reverse them which are listed below:

2nd and Up: Rotate left
Alpha: Rotate right
Left and Right: Move
Down: Soft Drop
Mode: Pause
Clear: Quit
Stat: Clear scores

### Randomness and Queue

Probably use a 16-bit LFSR or srand as a RNG.

The queue might be a array of puyo where the first two or four puyo is drawn
to the next boxes, the drawing of the puyo may be shifted over two where the
first two puyo are the ones that the player is placing them down.

## Separation Of Concern and Library

Separating the library from the graphics allows us to use different graphics
and game libraries or engines without rewriting the library for different
engines, because we are going to use it as "glue" for hooking the game to the
library.

## Saving and Loading

## Rules and Game Modes

This version will replicate the Original Puyo Puyo as said in the
[Board and Play Area](#board-and-play-area). But by having all other rules and
modes derive from OPP and the creation of the board, board checks, movement,
graphics are separate from each other. This makes the expansion of this port
faster.

### Nazo Puyo

Adding a puzzle challenge mode might be easy as the loading of the board is
different and the queue does not require the use of the RNG. We also might need
a win flag to play the next puzzle.

[^1]: https://puyonexus.com/wiki/Types_of_Puyo
