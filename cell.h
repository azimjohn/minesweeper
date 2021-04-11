struct cell_t {
private:
    bool is_mine = false;
    bool is_flagged = false;
    bool is_revealed = false;
    int adjacent_mines = 0;

public:
    char get_display_value();

    void place_mine();

    bool reveal();

    void flag();

    void unflag();

    void increment_adjacent_mines();

    bool auto_reveal();

    bool auto_reveal_neighbors();
};
