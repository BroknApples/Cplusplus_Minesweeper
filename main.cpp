#include <iostream>
#include <cmath>
#include <vector>
#include "automation.hpp"
#include "boards.hpp"

int main() {
    int rows = intro();
    int num_rows = pow(rows, 2);

    std::vector<char> spaces; // array that holds what the user will actually see
    std::vector<char> spaces_mines; // array that holds where the mines are

    for ( int i = 0; i < num_rows; i++ ) {
        spaces.push_back(' ');
        spaces_mines.push_back(' ');
    }

    // Start game
    int points = 0;

    while( !isDead(spaces, spaces_mines) ) {
        createMines(spaces_mines, rows, num_rows);
        drawBoard(spaces, rows, num_rows);
        isDead(spaces, spaces_mines);
        break;
    }
}