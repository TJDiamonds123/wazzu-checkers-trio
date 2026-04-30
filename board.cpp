#include "Board.hpp"
#include <iostream>

Board::Board(int s) : attackSound(attackBuffer) // Used ChatGPT to help configure the audio
{
    this->size = s;
    this->redHealth = 12;
    this->blackHealth = 12;

    this->redTurn = true;
    this->hasSelection = false;
    this->selectedRow = -1;
    this->selectedCol = -1;

    init();

    // Load Sound
    if (!attackBuffer.loadFromFile("Vine boom sound effect - Business Goose (128k).wav"))
    {
        std::cout << "Failed to load attack.wav" << std::endl;
    }

    attackSound.setBuffer(attackBuffer);
}

void Board::init()
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            grid[r][c] = 0;

            if ((r + c) % 2 == 1)
            {
                if (r < 3)
                    grid[r][c] = 2;
                else if (r > 4)
                    grid[r][c] = 1;
            }
        }
    }
}

bool Board::canCaptureAgain(int r, int c)
{
    // up left
    if (r - 2 >= 0 && c - 2 >= 0)
    {
        if (grid[r - 1][c - 1] != 0 && grid[r - 2][c - 2] == 0)
        {
            return true;
        }
    }

    // up right
    if (r - 2 >= 0 && c + 2 < 8)
    {
        if (grid[r - 1][c + 1] != 0 && grid[r - 2][c + 2] == 0)
        {
            return true;
        }
    }

    // down left
    if (r + 2 < 8 && c - 2 >= 0)
    {
        if (grid[r + 1][c - 1] != 0 && grid[r + 2][c - 2] == 0)
        {
            return true;
        }
    }

    // down right
    if (r + 2 < 8 && c + 2 < 8)
    {
        if (grid[r + 1][c + 1] != 0 && grid[r + 2][c + 2] == 0)
        {
            return true;
        }
    }

    return false;
}

void Board::whenClick(int row, int col)
{
    if (!hasSelection)
    {
        if (grid[row][col] != 0)
        {
            if ((redTurn && grid[row][col] == 1) ||
                (!redTurn && grid[row][col] == 2) ||
                grid[row][col] == 3 ||
                grid[row][col] == 4)
            {
                selectedRow = row;
                selectedCol = col;
                hasSelection = true;
            }
        }
        return;
    }

    int dr = row - selectedRow;
    int dc = col - selectedCol;

    int piece = grid[selectedRow][selectedCol];
    bool isKing = (piece == 3 || piece == 4);

    if (grid[row][col] == 0)
    {
        bool validMove = false;
        bool didCapture = false;

        // Normal move
        if (abs(dr) == 1 && abs(dc) == 1)
        {
            if (isKing)
                validMove = true;
            else
            {
                if (piece == 1 && dr == -1) validMove = true;
                if (piece == 2 && dr == 1) validMove = true;
            }
        }

        // Attack move
        if (abs(dr) == 2 && abs(dc) == 2)
        {
            int midRow = (row + selectedRow) / 2;
            int midCol = (col + selectedCol) / 2;

            if (grid[midRow][midCol] != 0 && grid[midRow][midCol] != piece)
            {
                // remove piece + update health
                if (piece == 1 || piece == 3)
                    blackHealth--;
                else
                    redHealth--;

                grid[midRow][midCol] = 0;

                // 🔊 PLAY SOUND ON ATTACK
                attackSound.play();

                didCapture = true;

                if (isKing)
                    validMove = true;
                else
                {
                    if (piece == 1 && dr == -2) validMove = true;
                    if (piece == 2 && dr == 2) validMove = true;
                }
            }
        }

        if (validMove)
        {
            grid[row][col] = piece;
            grid[selectedRow][selectedCol] = 0;

            // Promote to king
            if (piece == 1 && row == 0)
                grid[row][col] = 3;

            if (piece == 2 && row == 7)
                grid[row][col] = 4;

            if (didCapture && canCaptureAgain(row, col))
            {
                selectedRow = row;
                selectedCol = col;
                hasSelection = true;
            }
            else
            {
                redTurn = !redTurn;
                hasSelection = false;
            }
        }
    }

    hasSelection = false;
}

void Board::create(sf::RenderWindow& window)
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            sf::RectangleShape square(sf::Vector2f((float)size, (float)size));
            square.setPosition(sf::Vector2f((float)(c * size), (float)(r * size)));

            if ((r + c) % 2 == 0)
                square.setFillColor(sf::Color::White);
            else
                square.setFillColor(sf::Color(100, 100, 100));

            window.draw(square);

            if (grid[r][c] != 0)
            {
                Piece* p = nullptr;

                if (grid[r][c] == 1) p = new NormalPiece(true);
                else if (grid[r][c] == 2) p = new NormalPiece(false);
                else if (grid[r][c] == 3) p = new KingPiece(true);
                else if (grid[r][c] == 4) p = new KingPiece(false);

                if (p)
                {
                    p->draw(window, c * size, r * size, size);
                    delete p;
                }
            }
        }
    }
}

int Board::getBlack() const
{
    return blackHealth;
}

int Board::getRed() const
{
    return redHealth;
}

void Board::drawWinner(sf::RenderWindow& window, const std::string& text)
{
    sf::RectangleShape overlay(sf::Vector2f(800.f, 800.f));
    overlay.setFillColor(sf::Color(0, 0, 0, 180));
    window.draw(overlay);

    sf::RectangleShape box(sf::Vector2f(500.f, 200.f));
    box.setPosition(sf::Vector2f(150.f, 300.f));
    box.setFillColor(sf::Color(60, 60, 60));
    box.setOutlineThickness(4.f);
    box.setOutlineColor(sf::Color::White);
    window.draw(box);

    sf::RectangleShape indicator(sf::Vector2f(80.f, 80.f));
    indicator.setPosition(sf::Vector2f(360.f, 360.f));

    if (text == "Red Wins!")
        indicator.setFillColor(sf::Color::Red);
    else
        indicator.setFillColor(sf::Color::Black);

    window.draw(indicator);
}
