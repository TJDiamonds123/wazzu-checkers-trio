#include "Board.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {


	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 800)), "Checkers Board");

	int size = 100;


	Board board(size);


	while (window.isOpen()) {

		while (auto event = window.pollEvent()) {

			window.clear();
			board.create(window);
			window.display();


			if (event->is<sf::Event::Closed>()) {
				window.close();
			}

		}





	}


	return 0;
}
