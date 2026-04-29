#include "Board.hpp"

Board::Board(int s)
{
    this->size = s;
    this->redHealth = 12;
    this->blackHealth = 12;

    this->redTurn = true;
    this->hasSelection = false;
    this->selectedRow = -1;
    this->selectedCol = -1;

    init();
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
                {
                    grid[r][c] = 2;
                }
                else if (r > 4)
                {
                    grid[r][c] = 1;
                }
            }
        }
    }
}

void Board::whenClick(int row, int col)
{
    if (!hasSelection)
    {
        if (grid[row][col] != 0)
        {
            if ((redTurn && grid[row][col] == 1) || (!redTurn && grid[row][col] == 2) || grid[row][col] == 3 || grid[row][col] == 4)
            {
                this->selectedRow = row;
                this->selectedCol = col;
                this->hasSelection = true;
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

        // Normal move
        if (abs(dr) == 1 && abs(dc) == 1)
        {
            if (isKing)
            {
                validMove = true; // kings move both directions
            }
            else
            {
                if (piece == 1 && dr == -1)
                {
                    validMove = true;
                }
                if (piece == 2 && dr == 1)
                {
                    validMove = true;
                }
            }
        }

        // Attack move
        if (abs(dr) == 2 && abs(dc) == 2)
        {
            int midRow = (row + selectedRow) / 2;
            int midCol = (col + selectedCol) / 2;

            if (grid[midRow][midCol] != 0 && grid[midRow][midCol] != piece)
            {
                if (piece == 1 || piece == 3)
                {
                    this->blackHealth--;
                }
                else
                {
                    this->redHealth--;
                }

                this->grid[midRow][midCol] = 0;

                if (isKing)
                {
                    validMove = true;
                }
                else
                {
                    if (piece == 1 && dr == -2)
                    {
                        validMove = true;
                    }
                    if (piece == 2 && dr == 2)
                    {
                        validMove = true;
                    }
                }
            }
        }

        if (validMove)
        {
            this->grid[row][col] = piece;
            this->grid[this->selectedRow][this->selectedCol] = 0;

            // Promote to king
            if (piece == 1 && row == 0)
            {
                this->grid[row][col] = 3;
            }

            if (piece == 2 && row == 7)
            {
                this->grid[row][col] = 4;
            }

            this->redTurn = !this->redTurn;
        }
    }

    this->hasSelection = false;
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
            {
                square.setFillColor(sf::Color::White);
            }
            else
            {
                square.setFillColor(sf::Color(100, 100, 100));
            }

            window.draw(square);

            if (grid[r][c] != 0)
            {
                Piece* p = nullptr;

                if (grid[r][c] == 1)
                {
                    p = new NormalPiece(true);
                }
                else if (grid[r][c] == 2)
                {
                    p = new NormalPiece(false);
                }
                else if (grid[r][c] == 3)
                {
                    p = new KingPiece(true);
                }
                else if (grid[r][c] == 4)
                {
                    p = new KingPiece(false);
                }

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
    {
        indicator.setFillColor(sf::Color::Red);
    }
    else
    {
        indicator.setFillColor(sf::Color::Black);
    }

    window.draw(indicator);
}
