#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unordered_set>
#include "board.h"
#include "gameover.h"

using std::cout;
using std::endl;
using std::fstream;
using std::pair;
using std::unordered_set;


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
    int i = 0;
    srand(time(nullptr));
    unordered_set<int> positions;

    while (i < count){
        int pos = rand() % (width * height);
        if (positions.count(pos) > 0)
            continue;
        int row = pos / width;
        int col = pos % width;
        positions.insert(pos);

        place_mine(row, col);
        ++i;
    }
}

void board_t::place_mine(unsigned int row, unsigned int col) {
    cells[row][col]->place_mine();

    vector<pair<int, int>> neighbours{
        {row-1, col-1},
        {row-1, col+0},
        {row-1, col+1},
        {row+0, col-1},
        {row+0, col+1},
        {row+1, col-1},
        {row+1, col+0},
        {row+1, col+1},
    };

    for(auto pos : neighbours){
        int i = pos.first;
        int j = pos.second;

        if(i >= 0 && i < height && j >= 0 and j < width)
            cells[i][j]->increment_adjacent_mines();
    }
}

void board_t::display()
{
    cout << endl << "  ";
    for(int i = 0; i < width; ++i)
        cout << i;
    cout << endl;

    for(int i = 0; i < height; ++i){
        cout << i << " ";
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
    cout << "Took Screenshot" << endl;
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
