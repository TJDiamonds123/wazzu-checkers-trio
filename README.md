# wazzu-checkers-trio
pivoting to checkers since 1984







-board.hpp 
#pragma once


#include <SFML/Graphics.hpp>

class Board {
private: int size; 



public:
 Board(int s);
 void create(sf::RenderWindow& window);
};


- main.cpp

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

-board.cpp 
 #include "Board.hpp"



Board::Board(int s) {
	size = s;
}


void Board::create(sf::RenderWindow& window) {
	for (int r = 0; r < 8; r++) {//this is for the rows
		for (int c = 0; c < 8; c++) {
			sf::RectangleShape square(sf::Vector2f(size, size));//create squares

			square.setPosition(c * size, r * size);


			if ((r + c) % 2 == 0) {
				square.setFilColor(sf::Color::White);

			}
			else {
				square.setFilColor(sf::Color::Black);
			}

			window.draw(square);
		}





	}
}

