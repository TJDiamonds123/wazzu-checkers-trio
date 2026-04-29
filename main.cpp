#include "Board.hpp"



int main() {


	sf::RenderWindow window(sf::VideoMode(800, 800), " Checker Board");

	int size = 100;


	Board board(size);


	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {


			if (event.type == sf::Event::Closed) {
				window.closed();
			}

		}


		window.clear();
		board.draw(window);
		window.display();




	}


	return 0;
}