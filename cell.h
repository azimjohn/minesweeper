#include <string>
#include <SFML/Graphics.hpp>

using std::string;


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

    sf::Sprite *sprite;
};
