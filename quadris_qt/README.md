# Quadris QT

## Description

Quadris is a Latinized version of the game Tetris. Unlike Tetris, Quadris is not played in real-time. Players have as much time as they need to decide where to place a block on the board.

## Blocks

There are seven types of blocks:
- **I-block**
- **J-block**
- **L-block**
- **O-block**
- **S-block**
- **Z-block**
- **T-block**

## Board

The game board is 11 columns wide and 15 rows high. Three extra rows at the top are reserved for block rotations. Blocks appear in the top-left corner below the reserved rows.

## Display

The game utilizes a QT graphics display.

## Difficulty Levels

1. **Level 0:** Non-random sequence from a file (default: `sequence.txt`).
2. **Level 1:** Random selection skewed away from S and Z blocks.
3. **Level 2:** Equal probability for all blocks.
4. **Level 3:** Random selection skewed towards S and Z blocks; blocks are "heavy", every command to
move or rotate the block will be followed immediately and automatically by a downward move
of one row (if possible).
5. **Level 4:** In addition to the rules of Level 3, in Level 4 there is an external constructive force:
every time you place 5 blocks without clearing at least one row, a 1x1 block is dropped onto your
game board in the centre column. Once dropped, it acts like any other block: if it completes a row, the row disappears.

## Keystrokes (Commands)

To play the game, use the following keystrokes:

- **Movement:**
  - `Left Arrow`: Move block to the left
  - `Right Arrow`: Move block to the right
  - `Down Arrow`: Move block downwards
  - `Space`: Drop the block immediately
  
- **Rotation:**
  - `C`: Rotate block clockwise
  - `X`: Rotate block counterclockwise

- **Gameplay:**
  - `+` or `=`: Level up
  - `-`: Level down
  - `R`: Press twice quickly to restart the game
  - `H`: Show hint

## Scoring

- Points awarded for cleared lines and completely removed blocks.
- Game tracks current score and high score.

## Getting Started

### Prerequisites

Ensure you have the appropriate QT libraries installed.

### Compilation

To compile the project, follow the steps below:

1. Navigate to the project directory:
```
cd path/to/quadris_qt
```

2. Create and navigate to the build directory:
```
mkdir build
cd build
```

4. Run CMake and build the project:
```
cmake ..
make
```

### Running Quadris QT

To start the game, use the following command from the build directory:
```
open Quadris.app
```

### Gameplay

After starting the game, use the Keystrokes (Commands) section of this README as a guide to playing Quadris QT. Navigate, rotate, and position the blocks as they appear on the board using the provided keystrokes. Aim to clear lines and maximize your score!
