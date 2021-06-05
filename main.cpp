#include <iostream>
#include <SFML/Graphics.hpp>

#include "board.h"
#include "gameover.h"

#define BOARD_WIDTH 15
#define BOARD_HEIGHT 15
#define MINES 20
#define CELL_SIZE 50

using std::cin;
using std::cout;
using std::endl;


int main() {
    board_t board(BOARD_WIDTH, BOARD_HEIGHT);
    board.place_mines(MINES);

    int width = BOARD_WIDTH * CELL_SIZE;
    int height = BOARD_HEIGHT * CELL_SIZE;
    auto style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(width, height), "Minesweeper Game", style);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window.display();
    }
}
