#include "Board.hpp"



int main() {


	sf::RenderWindow window(sf::VideoMode(800, 800), " Checker Board");

	int size = 100;


	Board board(size);


	while (window.isOpen()) {

		while( autor event = window.pollEvent()){
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}

		}


		window.clear();
		board.draw(window);
		window.display();




	}


	return 0;
}
