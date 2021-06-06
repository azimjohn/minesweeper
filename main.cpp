#include <iostream>
#include <SFML/Graphics.hpp>
#include "texture_manager.h"
#include "board.h"
#include "gameover.h"

#define BOARD_WIDTH 12
#define BOARD_HEIGHT 12
#define MINES 20
#define CELL_SIZE 50
#define KEY_R 17

using std::cin;
using std::cout;
using std::endl;


void show_manual(){
    cout << "Manual:" << endl;
    cout << "\tReveal Cell\t - Mouse Left Click" << endl;
    cout << "\tFlag Cell\t - Mouse Right Click" << endl;
    cout << "\tReset Board\t - Press 'R' on Keyboard" << endl;
}

int main() {
    show_manual();
    board_t board(BOARD_WIDTH, BOARD_HEIGHT);
    board.place_mines(MINES);

    bool isGameOver = false;
    int width = BOARD_WIDTH * CELL_SIZE;
    int height = BOARD_HEIGHT * CELL_SIZE;
    auto style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(width, height), "MineSweeper Game", style);
    TextureManager textureManager;
    textureManager.loadAll();

    board.draw(&window, &textureManager, CELL_SIZE);
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == KEY_R){
                    isGameOver = false;
                    board.reset();
                    board.place_mines(MINES);
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && !isGameOver)
            {
                int i = event.mouseButton.x / CELL_SIZE;
                int j = event.mouseButton.y / CELL_SIZE;

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    try
                    {
                        board.reveal_cell(i, j);
                    }
                    catch(GameOver& e)
                    {
                        isGameOver = true;
                        board.reveal_all_cells();
                    }
                }
                else
                {
                    board.toggle_flag_cell(i, j);
                }
            }

            board.draw(&window, &textureManager, CELL_SIZE);
            window.display();
        }
    }
}
