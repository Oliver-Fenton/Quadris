# Quadris Game Repository

This repository contains two C++ implementations of the game Quadris:
1. A version with a Command Line Interface (CLI) and an optional X11 graphics display.
2. A version that utilizes a Qt-based graphical user interface (GUI).

## Introduction to Quadris

Quadris is a Latinization of the popular game Tetris. The gameplay revolves around manipulating tetrominoes (blocks composed of 4 cells) which appear at the top of the screen and need to be placed strategically on the board without leaving any gaps. When a row is entirely filled with blocks, it disappears, and the blocks situated above will move down by one unit.

The fundamental distinction between Tetris and Quadris is the pacing: Quadris is not played in real-time, giving the player as much time as desired to decide the placement of a block.

## Game Components

- **Blocks**: There are seven distinct types of blocks, each having its unique shape:
  - I-block
  - J-block
  - L-block
  - O-block
  - S-block
  - Z-block
  - T-block

- **Board**: Quadris's board is structured as 11 columns wide and 15 rows high. Three extra rows are reserved at the top to allow for block rotation.

- **Display**: The CLI-based version uses a text display, optional X11 display, and text commands. The Qt-based version uses a GUI and keystroke commands.

- **Block Selection**: The game offers varying difficulty levels that dictate the sequence and randomness of block generation.

- **Scoring**: Points are awarded for clearing lines and for completely removing blocks from the board.

## Gameplay Mechanics

Quadris offers a unique blend of strategic thinking and spatial awareness, challenging players to fill rows efficiently while planning for upcoming tetrominoes. Unlike traditional Tetris, the non-real-time nature of Quadris means players have as much time as they need to consider their next move.

## Getting Started

To delve into Quadris, navigate to the desired version (CLI or Qt GUI) and follow the setup and gameplay instructions provided therein.


> **Note**: This README provides an overview of the Quadris game, its mechanics, and the two implementations available in this repository.

