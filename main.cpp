#include <iostream>
#include <vector>
#include "automation.hpp"
#include "boards.hpp"

int main() {
    int rows = intro();
    int num_rows = rows * rows;
    int user_move;

    std::vector<char> spaces; // array that holds what the user will actually see
    std::vector<char> spaces_mines; // array that holds where the mines are
    std::vector<bool> bool_spaces; // array that holds the conditions to win

    for ( int i = 0; i <= num_rows; i++ ) {
        spaces.push_back(' ');
        spaces_mines.push_back(' ');
        bool_spaces.push_back(false);
    }

    // Start game
    int points = 0;
    createMines(spaces_mines, rows, num_rows);
    do {
        drawBoard(spaces_mines, rows, num_rows);
        drawBoard(spaces, rows, num_rows);
        user_move = getUserMove(rows, spaces);
        if ( checkWin(spaces, spaces_mines, num_rows, bool_spaces) ) {
            isDead(spaces, spaces_mines, num_rows, points, user_move, rows);
            mergeBoards(spaces, spaces_mines, num_rows);
            drawBoard(spaces, rows, num_rows);
            std::cout << "You win!\nYou safely marked " << points << " spaces!\n";
            drawGameSpaceEnd(rows);
            return 0;
        }
    } while( !isDead(spaces, spaces_mines, num_rows, points, user_move, rows) );

    if ( isDead(spaces, spaces_mines, num_rows, points, user_move, rows) ) {
        std::cout << "You lost\n";
        switch(points) {
            case 1:
                std::cout << "You had " << points << " point!\n";
                break;
            default:
                std::cout << "You had " << points << " points!\n";
        }
    }

    return 0;
}