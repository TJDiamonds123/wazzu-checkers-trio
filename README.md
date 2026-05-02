 # Checkers

This is a simple Checkers game built in C++ using "SFML" libraries, particularly the graphics and audio libraries. 
We tried to make it as close as we could to normal checkers.

## Rules

* 8x8 checkers board
* Player 1 (RED) against Player 2 (BLACK)
* Player 1 (RED) goes first, Player 2 (BLACK) goes after Player 1 (RED)
* You can only move diagonally forward, jumping over any opposing color pieces to capture them (eliminate them)
* King promotion happens on the opposite end of the board from your starting side (pieces can move backwards after becoming king)
* You must take all of the opponents pieces to win the game

## Controls

* Click a piece to select it, then click a valid square to move. On the menu screen are green and red rectangles. Press the red button to quit and the green button to start the game.

## Setup Instructions

1. Install **SFML 3.1.0**
2. Configure SFML in Visual Studio to include the Graphics and Audio libraries
(This tutorial helps with configuring SFML: https://www.sfml-dev.org/tutorials/3.0/getting-started/visual-studio/#creating-and-configuring-an-sfml-project )
4. Build and run the project

## Polymorphism

* Polymorphism is used from a derived Piece.hpp class into KingPiece.hpp and NormalPiece.hpp separately. This polymorphism is for each piece and they behave differently based on the class it is. Whether its a normal piece or a king piece. The program treats all the pieces the same but draw them differently based on the case.

## Video

* This is a link to the video showing the program running: 

## Authors

Created by:

* Noah Hunt - Lab Section 1
* Kasen Koide - Lab Section 3
* Timothy Mullin - Lab Section 10
