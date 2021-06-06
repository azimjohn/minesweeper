#include "cell.h"


void cell_t::place_mine() {
    is_mine = true;
}

bool cell_t::reveal() {
    if (is_flagged) return false;

    is_revealed = true;
    return is_mine;
}

void cell_t::toggle_flag() {
    is_flagged = !is_flagged;
}

void cell_t::unflag() {
    is_flagged = false;
}

void cell_t::increment_adjacent_mines() {
    ++adjacent_mines;
}

bool cell_t::auto_reveal() {
    return !is_mine;
}

bool cell_t::auto_reveal_neighbors() {
    return !is_mine && adjacent_mines == 0;
}

char cell_t::get_display_value() {
    if (is_flagged) return 'f';
    if (!is_revealed) return 'n';
    if (is_mine) return 'b';

    return (char) (adjacent_mines + '0');
}

void cell_t::reset() {
    is_flagged = false;
    is_revealed = false;
    is_mine = false;
}
