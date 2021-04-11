#include <vector>
#include "cell.h"

using std::vector;

struct board_t
{
private:
    int width;
    int height;
    vector<vector<cell_t*>> cells;

public:
    board_t(int W, int H);
    void place_mines(int count);
    void display();
    void screenshot();
    void reveal_cell(int row, int col);
    void reveal_all_cells();
    void flag_cell(int row, int col);
    void unflag_cell(int row, int col);
    ~board_t();
};
