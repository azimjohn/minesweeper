#include <iostream>
#include "board.h"
#include "gameover.h"

using std::cout;
using std::endl;
using std::fstream;


board_t::board_t(const int W, const int H)
{
    width = W;
    height = H;
    cells = new cell_t**[H];

    for(int i = 0; i < height; ++i) {
        cells[i] = new cell_t*[W];
        for (int j = 0; j < width; ++j) {
            cells[i][j] = new cell_t();
        }
    }
}


board_t::~board_t()
{
    for(int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
}


void board_t::place_mines(const int count)
{

}

void board_t::display()
{
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            cout << cells[i][j]->get_display_value();
        }
        cout << endl;
    }
    cout << endl;
}

void board_t::screenshot()
{
    fstream file;
    file.open("screenshot.txt", std::ios::out);
    if (!file.good()) {
        std::cout << "Error opening screenshot.txt" << std::endl;
        return;
    }

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            file << cells[i][j]->get_display_value();
        }
        file << endl;
    }

    file.close();
}

void board_t::reveal_cell(const unsigned int row, const unsigned int col)
{
    if (row >= height || col >= width)
        return;

    auto cell = cells[row][col];
    bool mine_revealed = cell->reveal();
    if(mine_revealed)
        throw GameOver();

    // todo: reveal all neighbouring cells with ripple effect;
}

void board_t::reveal_all_cells()
{
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            cells[i][j]->unflag();
            cells[i][j]->reveal();
        }
    }
}

void board_t::flag_cell(const unsigned int row, const unsigned int col)
{
    if (row < height && col < width)
        cells[row][col]->flag();
}

void board_t::unflag_cell(const unsigned int row, const unsigned int col)
{
    if (row < height && col < width)
        cells[row][col]->unflag();
}
