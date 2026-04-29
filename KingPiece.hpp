#pragma once
#include "Piece.hpp"

class KingPiece : public Piece
{
private:
    bool red;

public:
    KingPiece(bool isRed) : red(isRed) {}

    void draw(sf::RenderWindow& window, int x, int y, int size) override
    {
        sf::CircleShape piece(size / 2.5f);

        piece.setPosition(sf::Vector2f(
            (float)(x + 15),
            (float)(y + 15)
        ));

        piece.setFillColor(red ? sf::Color(255, 80, 80)
            : sf::Color(70, 70, 70));

        piece.setOutlineThickness(4.f);
        piece.setOutlineColor(sf::Color::Yellow);

        window.draw(piece);
    }
};
