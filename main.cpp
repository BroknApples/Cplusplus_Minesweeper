#include <iostream>
#include <cmath>
#include <vector>
#include "automation.hpp"
#include "drawBoard.hpp"
#include "introduction.hpp"

int main() {
    /*
    use multidimensional array to show the amount of rows. Will probably have to use dfs to check num of mines near any specific point
    */
    int rows = intro();
    int num_rows = pow(rows, 2);

    std::vector<char> spaces; // array that holds what the user will actually see
    std::vector<char> spaces_mines; // array that holds where the mines are

    for ( int i = 0; i < num_rows; i++ ) {
        spaces.push_back(' ');
        spaces_mines.push_back(' ');
    }

    // Start game
    while( !isDead(spaces, spaces_mines) ) {
        spaces[8] = 'X';
        drawBoard(spaces, rows);
        break;
    }
}