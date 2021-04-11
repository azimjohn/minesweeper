#include "cell.h"


char cell_t::get_display_value()
{
    if(!is_revealed) 
        return ' ';
    
    if(is_flagged)
        return 'F';

    if(is_mine) 
        return 'X';

    return adjacent_mines + '0';
}

void cell_t::place_mine()
{
    is_mine = true;    
}

bool cell_t::reveal()
{
    if(is_flagged) 
        return false;
    
    is_revealed = true;
    return is_mine;
}

void cell_t::flag()
{
    is_flagged = true;
}

void cell_t::unflag()
{
    is_flagged = false;
}

void cell_t::increment_adjacent_mines(){
    ++adjacent_mines;
}
