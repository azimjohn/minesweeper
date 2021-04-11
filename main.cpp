#include <iostream>
#include "board.h"
#include "gameover.h"

using std::cin;
using std::cout;
using std::endl;

void start_game(board_t* board);

void show_manual()
{
    cout << "Game Manual: " << endl;
    cout << "\tS - screenshot" << endl;
    cout << "\tR {r} {c} - reveal {r} {c} cell" << endl;
    cout << "\tF {r} {c} - flag   {r} {c} cell" << endl;
    cout << "\tU {r} {c} - unflag {r} {c} cell" << endl;
}

int main(){
    int width = 20, height = 10, mines = 42;

    board_t board{width, height};
    board.place_mines(mines);
    show_manual();

    try {
       start_game(board);
    } catch(GameOver e){
        board.reveal_all_cells();
        board.display();
        cout << "Game Over :(";
    }
}

void start_game(board_t* board){
    char action;
    int row, col;
    board->display();

    while(true)
    {
        cout << "Enter Action: ";
        cin >> action;

        switch (action)
        {
        case 'S', 's':
            board->screenshot();
            break;
        case 'R', 'r':
            cin >> row >> col;
            board->reveal_cell(row, col);
            break;
        case 'F', 'f':
            cin >> row >> col;
            board->flag_cell(row, col);
            break;
        case 'U', 'u':
            cin >> row >> col;
            board->unflag_cell(row, col);
            break;
        default:
            cout << "Unknown Action %c" % action << endl;
            break;
        }
        board->display();
    }
}