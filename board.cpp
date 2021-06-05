#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_set>
#include "board.h"
#include "gameover.h"

using std::pair;
using std::make_pair;
using std::queue;
using std::unordered_set;


board_t::board_t(const int W, const int H) {
    width = W;
    height = H;
    cells = new cell_t **[H];

    for (int i = 0; i < height; ++i) {
        cells[i] = new cell_t *[W];
        for (int j = 0; j < width; ++j) {
            cells[i][j] = new cell_t();
        }
    }
}

board_t::~board_t() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
}

void board_t::place_mines(const int count) {
    int i = 0;
    srand(time(nullptr));
    unordered_set<int> positions;

    while (i < count) {
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
    auto cell = cells[row][col];
    cell->place_mine();

    auto neighbours = get_adjacent_positions(row, col);
    for (auto pos : neighbours) {
        cells[pos.first][pos.second]->increment_adjacent_mines();
    }
}

vector<pair<int, int>> board_t::get_adjacent_positions(unsigned int row, unsigned int col) {
    vector<pair<int, int>> neighbours;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (row + i > 0 and row + i < height and col + j > 0 and col + j < width)
                neighbours.emplace_back(row + i, col + j);
        }
    }
    return neighbours;
}


void board_t::reveal_cell(const unsigned int row, const unsigned int col) {
    if (row >= height || col >= width)
        return;

    auto cell = cells[row][col];
    bool mine_revealed = cell->reveal();
    if (mine_revealed)
        throw GameOver();

    queue<pair<int, int>> q;
    unordered_set<cell_t *> visited;

    q.push(make_pair(row, col));

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        cell = cells[pos.first][pos.second];

        if (visited.count(cell) > 0) {
            continue;
        }
        visited.insert(cell);

        if (!cell->auto_reveal())
            continue;

        cell->reveal();
        if (cell->auto_reveal_neighbors()) {
            auto neighbors = get_adjacent_positions(pos.first, pos.second);
            for (auto neighbor : neighbors)
                q.push(neighbor);
        }
    }
}

void board_t::reveal_all_cells() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j]->unflag();
            cells[i][j]->reveal();
        }
    }
}

void board_t::flag_cell(const unsigned int row, const unsigned int col) {
    if (row < height && col < width)
        cells[row][col]->flag();
}

void board_t::unflag_cell(const unsigned int row, const unsigned int col) {
    if (row < height && col < width)
        cells[row][col]->unflag();
}
