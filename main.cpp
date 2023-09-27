#include <iostream>
#include <cmath>
#include <vector>
#include "automation.hpp"
#include "boards.hpp"

int main() {
    int rows = intro();
    int num_rows = pow(rows, 2);
    int user_move;

    std::vector<char> spaces; // array that holds what the user will actually see
    std::vector<char> spaces_mines; // array that holds where the mines are

    for ( int i = 0; i < num_rows; i++ ) {
        spaces.push_back(' ');
        spaces_mines.push_back(' ');
    }

    // Start game
    int points = 0;
    createMines(spaces, rows, num_rows);
    do {
        drawBoard(spaces, rows, num_rows);
        user_move = getUserMove(rows);
        if ( checkWin() ) {
            std::cout << "You win\n";
            return 0;
        }
    } while( !isDead(spaces, spaces_mines, num_rows, points, user_move, rows) );

    if ( isDead(spaces, spaces_mines, num_rows, points, user_move, rows) ) {
        std::cout << "You lost\n";
    }
}