#pragma once
#include "Piece.hpp"// base class polymorphism
//the same concept as the kingpiece.hpp
class NormalPiece : public Piece
{
private:
    bool red;// stores wheter is the piece red or black

public:
    NormalPiece(bool isRed) : red(isRed) {}//cosntructor for the determine color

    void draw(sf::RenderWindow& window, int x, int y, int size) override
    {

        //creates the piece whether that is size, position or color
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
