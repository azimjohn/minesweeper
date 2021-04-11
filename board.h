#include <vector>
#include <fstream>
#include "cell.h"

using std::vector;
using std::pair;
using std::fstream;

struct board_t
{
private:
    int width;
    int height;
    cell_t*** cells;

public:
    board_t(int W, int H);
    void place_mines(int count);
    void place_mine(unsigned int row, unsigned int col);
    void display();
    void screenshot();
    void reveal_cell(unsigned int row, unsigned int col);
    void reveal_all_cells();
    void flag_cell(unsigned int row, unsigned int col);
    void unflag_cell(unsigned int row, unsigned int col);
    vector<pair<int, int>> get_adjacent_positions(unsigned int row, unsigned int col);
    ~board_t();
};
