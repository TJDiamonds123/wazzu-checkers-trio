#pragma once
#include "Piece.hpp"

class NormalPiece : public Piece
{
private:
    bool red;

public:
    NormalPiece(bool isRed) : red(isRed) {}

    void draw(sf::RenderWindow& window, int x, int y, int size) override
    {
        sf::CircleShape piece(size / 2.5f);

        piece.setPosition(sf::Vector2f((float)(x + 15), (float)(y + 15)));

        if (red)
        {
            piece.setFillColor(sf::Color::Red);
        }
        else
        {
            piece.setFillColor(sf::Color::Black);
        }

        window.draw(piece);
    }
};
