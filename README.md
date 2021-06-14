# minesweeper
Minesweeper Game - in C++

<img src="https://azimjon.com/media/2021/06/14/ezgif-2-b1b4e2f40650.gif" width="540">

### Definition of `Cell`
```cpp
// cell.h

struct cell_t {
private:
    bool is_mine = false;
    bool is_flagged = false;
    bool is_revealed = false;
    int adjacent_mines = 0;

public:
    cell_t();
    ~cell_t();
    void place_mine();
    bool reveal();
    void toggle_flag();
    void unflag();
    void increment_adjacent_mines();
    bool auto_reveal();
    bool auto_reveal_neighbors();
    char get_display_value();
    void reset();
};
```

### Definition of `Board`
```cpp
// board.h

struct board_t {
private:
    int width;
    int height;
    cell_t ***cells;

public:
    board_t(int W, int H);
    ~board_t();
    void reset();
    void place_mines(int count);
    void place_mine(unsigned int row, unsigned int col);
    void reveal_cell(unsigned int row, unsigned int col);
    void reveal_all_cells();
    void toggle_flag_cell(unsigned int row, unsigned int col);
    void draw(sf::RenderWindow* window, TextureManager *textureManager, int cell_size);
    vector<pair<int, int> > get_adjacent_positions(unsigned int row, unsigned int col);
};
```
