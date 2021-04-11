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
    board_t(const int W, const int H);
    void place_mines(const int count);
    void display();
    void screenshot();
    void reveal_cell(const int row, const int col);
    void reveal_all_cells();
    void flag_cell(const int row, const int col);
    void unflag_cell(const int row, const int col);
    ~board_t();
};
