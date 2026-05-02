#pragma once
#include "Piece.hpp" // base class piece polymorphism

class KingPiece : public Piece
{
private:
    bool red;// stores the color piece

public:
    KingPiece(bool isRed) : red(isRed) {}//constructor sets if the king is red or not

    void draw(sf::RenderWindow& window, int x, int y, int size) override//draw the function from the piece class
    {

        //creates the piece, where the color, size, or king
        sf::CircleShape piece(size / 2.5f);

        piece.setPosition(sf::Vector2f((float)(x + 15), (float)(y + 15)));

        if (red)
        {
            piece.setFillColor(sf::Color(255, 80, 80));
        }
        else
        {
            piece.setFillColor(sf::Color(70, 70, 70));
        }

        piece.setOutlineThickness(4.f);
        piece.setOutlineColor(sf::Color::Yellow);

        window.draw(piece);
    }
};
