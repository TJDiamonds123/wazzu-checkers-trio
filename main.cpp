    #include "Board.hpp"
    #include <SFML/Graphics.hpp>
    #include <string>

    int main()
    {
        sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Checkers");

        int size = 100;
        Board board(size);

        bool menu = true;
        std::string winner = "";

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

                    if (menu)
                    {
                        if (x > 250 && x < 550 && y > 250 && y < 350)
                        {
                            menu = false;
                        }
                        else if (x > 250 && x < 550 && y > 400 && y < 500)
                        {
                            window.close();
                        }
                    }
                    else
                    {
                        int col = x / size;
                        int row = y / size;

                        board.whenClick(row, col);
                    }
                }
            }

            // WIN CHECK
            if (!menu)
            {
                if (board.getBlack() == 0)
                    winner = "Red Wins!";
                else if (board.getRed() == 0)
                    winner = "Black Wins!";
            }

            window.clear();

            if (menu)
            {
                sf::RectangleShape start(sf::Vector2f(300.f, 100.f));
                start.setPosition(sf::Vector2f(250.f, 250.f));
                start.setFillColor(sf::Color::Green);

                sf::RectangleShape exit(sf::Vector2f(300.f, 100.f));
                exit.setPosition(sf::Vector2f(250.f, 400.f));
                exit.setFillColor(sf::Color::Red);

                window.draw(start);
                window.draw(exit);
            }
            else
            {
                board.create(window);

                if (!winner.empty())
                {
                    board.drawWinner(window, winner);
                }
            }

            window.display();
        }

        return 0;
    }
