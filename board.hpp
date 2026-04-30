#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "NormalPiece.hpp"
#include "KingPiece.hpp"

class Board
{
private:
    int size;
    int grid[8][8];

    int redHealth;
    int blackHealth;

    bool redTurn;
    bool hasSelection;
    int selectedRow;
    int selectedCol;

public:
    Board(int s);
    bool canCaptureAgain(int r, int c);

    void init();
    void create(sf::RenderWindow& window);
    void whenClick(int row, int col);

    int getBlack() const;
    int getRed() const;

    void drawWinner(sf::RenderWindow& window, const std::string& text);
};
