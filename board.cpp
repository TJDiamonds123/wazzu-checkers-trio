#include "Board.hpp"



Board::Board(int s) {
	size = s;
}


void Board::create(sf::RenderWindow& window) {
	for (int r = 0; r < 8; r++) {//this is for the rows
		for (int c = 0; c < 8; c++) {
			sf::RectangleShape square(sf::Vector2f((float)size, (float)size));//create squares

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

