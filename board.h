#include "cell.h"


struct board_t
{
    cell_t** cells = nullptr;
    int width;
    int height;

    board_t(const int W, const int H);
    void place_mines(const int count);
    void display();
    void reveal_cell(const int row, const int col);
};
