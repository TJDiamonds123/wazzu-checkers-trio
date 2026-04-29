#include "Board.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 800)), "Checkers");

    int size = 100;
    Board board(size);

    std::string winner = "\0";

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>())
            {
                auto pos = sf::Mouse::getPosition(window);

                int col = pos.x / size;
                int row = pos.y / size;

                board.whenClick(row, col);
            }
        }

        if (board.getBlack() == 0)
        {
            winner = "Red Wins!";
        }
        else if (board.getRed() == 0)
        {
            winner = "Black Wins!";
        }

        window.clear();
        board.create(window);

        if (winner != "\0")
        {
            board.drawWinner(window, winner);
        }

        window.display();
    }

    return 0;
;
}
