#include <iostream>
#include "board.h"
#include "gameover.h"

#define WINDOW_WIDTH 10
#define WINDOW_HEIGHT 10
#define MINES 10

using std::cin;
using std::cout;
using std::endl;

void start_game(board_t* board);

void show_manual()
{
    cout << "Game Manual: " << endl;
    cout << "\tS - take screenshot" << endl;
    cout << "\tR {r} {c} - reveal [r,c] cell" << endl;
    cout << "\tF {r} {c} - flag   [r,c] cell" << endl;
    cout << "\tU {r} {c} - unflag [r,c] cell" << endl;
    cout << "\tQ - Quit Game" << endl;
}

int main(){
    board_t board{WINDOW_WIDTH, WINDOW_HEIGHT};
    board.place_mines(MINES);
    show_manual();

    try {
       start_game(&board);
    } catch(GameOver& e){
        board.reveal_all_cells();
        board.display();
        cout << e.what();
    }
}

void start_game(board_t* board){
    char action;
    unsigned int row, col;
    board->display();

    while(true)
    {
        cout << "Enter Action: ";
        cin >> action;

        switch (action)
        {
        case 'S':
            board->screenshot();
            continue;
        case 'R':
            cin >> row >> col;
            board->reveal_cell(row, col);
            break;
        case 'F':
            cin >> row >> col;
            board->flag_cell(row, col);
            break;
        case 'U':
            cin >> row >> col;
            board->unflag_cell(row, col);
            break;
        case 'Q':
            return;
        default:
            cout << "Unknown Action: " << action << endl;
            continue;
        }
        board->display();
    }
}