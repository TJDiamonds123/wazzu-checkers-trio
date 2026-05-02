#include "Board.hpp"
#include "Test.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Checkers");

    int size = 100;
    Board board(size);
    Test validate;
    bool gameReady = false;

    bool menu = true;
    std::string winner = "";

    sf::Music music; // Background music

    sf::Music fanfare; // Victory music
    bool musicFlag = true; // Checks if victory music has already been played


    if (!fanfare.openFromFile("AwesomeSoundEffect.wav"))
    {
        std::cout << "Failed to load fanfare" << std::endl;
    }



    //Validates code
    if (!validate.runAllTests())
    {
        std::cout << "Error: Test cases not working";
        return -1;
    }
 

    // Loads music
    if (music.openFromFile("music.wav"))
    {
        music.play();
    }
    else
    {
        std::cout << "Failed to load music" << std::endl;
        return -1;
    }


    // Application passes checks
    std::cout << "[Complete]: Application running...";


    // Runs main application
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
            {
                winner = "Red Wins!";
            }
            else if (board.getRed() == 0)
            {
                winner = "Black Wins!";
            }
        }


        // Checks for fanfare flag
        if ((board.getBlack() == 0 || board.getRed() == 0) && musicFlag)
        {
            fanfare.play();
            musicFlag = false;
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