# Quadris CLI

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

There is a CLI and a X11 graphics display.

## Difficulty Levels

1. **Level 0:** Non-random sequence from a file (default: `sequence.txt`).
2. **Level 1:** Random selection skewed away from S and Z blocks.
3. **Level 2:** Equal probability for all blocks.
4. **Level 3:** Random selection skewed towaards S and Z blocks; blocks are "heavy", every command to
move or rotate the block will be followed immediately and automatically by a downward move
of one row (if possible).
5. **Level 4:** In addition to the rules of Level 3, in Level 4 there is an external constructive force:
every time you place 5 blocks without clearing at least one row, a 1x1 block is dropped onto your
game board in the centre column. Once dropped, it acts like any other block: if it completes a row, the row disappears.

## Commands

- **Movement:** `left`, `right`, `down`, `drop`
- **Rotation:** `clockwise`, `counterclockwise`
- **Gameplay:** `levelup`, `leveldown`, `restart`
- **Testing:** `norandom`, `random`, `sequence`, `I`, `J`, `L`, etc.
*(Note: Prefix multipliers can be added to repeat commands. Only as much of a command as is necessary to distinguish it from other commands needs to be entered.)*

## Scoring

- Points awarded for cleared lines and completely removed blocks.
- Game tracks current score and high score.

## Command-line Interface

- `-text`: Text-only mode. No graphics are displayed.
- `-seed xxx`: Set seed for randomness.
- `-scriptfile xxx`: Choose block source file for level 0.
- `-startlevel n`: Start at a specified level. The game starts in level 0 if this option is not supplied.

## Getting Started

To begin playing Quadris via CLI, follow the steps outlined below:

### Prerequisites

- `g++`: Ensure you have the GNU C++ compiler installed.
- `X11`: Required for the graphical display component of the project.

### Compilation

To compile the project, follow the steps below:

1. Navigate to the project directory:
```
cd path/to/your/project
```

2. Run the `make` command to compile the project:
```
make
```

After successful compilation, you should find the executable named `quadris` in the current directory.

### Running Quadris

To start the game, use the following command:
```
./quadris [OPTIONS]
```
Where [OPTIONS] can be any combination of the Command-line Interface options described above, such as -text, -seed xxx, -scriptfile xxx, and -startlevel n.

### Gameplay

After starting the game, you can use the Commands section of this README as a guide to playing Quadris. Navigate, rotate, and position the blocks as they appear on the board using the provided commands. Aim to clear lines and maximize your score!

### Exiting the Game

End-of-file (EOF) terminates the game, typically `CTRL + D` on your keyboard.
