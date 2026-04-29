#pragma once
#include <SFML/Graphics.hpp>

class Piece
{
public:
    virtual ~Piece() {}

    virtual void draw(sf::RenderWindow& window, int x, int y, int size) = 0;
};
