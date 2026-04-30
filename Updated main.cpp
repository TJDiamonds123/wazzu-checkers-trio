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
                int x = pos.x;
                int y = pos.y;

                if (menu == true) {
                    if (x > 250 && x < 550 && y> 250 && y < 350) {
                        menu = false
                    }
                    if (x > 250 && x < 550 && y > 400 && y < 500) {
                        window. close
                    }

                }
                else {

                    int col = pos.x / size;
                    int row = pos.y / size;

                    board.whenClick(row, col);
                }
            }
        }
        if (menu == false) {
            if (board.getBlack() == 0)
            {
                winner = "Red Wins!";
            }
            else if (board.getRed() == 0)
            {
                winner = "Black Wins!";
            }
        }
        

        window.clear();

        if (menu == true) {
            sf::RectangleShape start(sf::Vector2f(300, 100));
            start.setPosition(250, 250);
            start.setFillColor(sf::Color::Green);


            sf::RectangleSHape exit(sf::Vector2f(300, 100));
            exit.setPosition(250, 400);
            exit.setFillColor(sf::color::Red);

            window.draw(start);
            window.draw(exit);
        }
        else {
board.create(window);
   if (winner != "\0")
        {
            board.drawWinner(window, winner);
        }

        window.display();
    }



        }
        

     

    return 0;
    
}
