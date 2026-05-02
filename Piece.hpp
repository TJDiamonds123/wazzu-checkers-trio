#pragma once
#include <SFML/Graphics.hpp>

class Piece
{
public:
    virtual ~Piece() {}//virtural destrctor  for cleanup
//pure virtural function that makes all piece class to implement their own draw. polymorphism is used so the pieces are different
    virtual void draw(sf::RenderWindow& window, int x, int y, int size) = 0;
};
