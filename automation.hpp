#include <iostream>
#include <vector>
#include <sstream>

int intro() {
    // Returns number of spaces utilized in the game
    int rows;
    do {
        std::cout << "Enter the nummber of rows you would like to play with(5 - 26): ";
        std::cin >> rows;
    } while( rows < 5 || rows > 26 );

    // Output a gamespace header
    for ( int i = 0; i < ((rows  - 4) + (rows / 4)); i++ ) {
        std::cout << "*";
    }
    std::cout << "WELCOME TO MINESWEEPER";
     for ( int i = 0; i < ((rows  - 4) + (rows / 4)); i++ ) {
        std::cout << "*";
    }
    std::cout << std::endl;
    return rows;
}


int searchAmountOfMines( std::vector<char> spaces_mines, int user_move, int rows, int num_rows ) {
    int user_move_p1 = user_move + 1;
    int num_of_mines = 0;

    // Check corners
    if      ( user_move_p1 == rows ) { // Check top right corner
        if ( spaces_mines[(rows * 2) - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(rows * 2) - 2] == '#' ) num_of_mines++;
        if ( spaces_mines[rows - 1] == '#' ) num_of_mines++;
    }
    else if ( user_move_p1 == num_rows ) { // Check bottom right corner
        if ( spaces_mines[(num_rows - 1) - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(num_rows - rows) - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(num_rows - rows) - 2] == '#' ) num_of_mines++;
    }
    else if ( user_move_p1 == (rows / rows) ) { // Check top left corner
        if ( spaces_mines[1] == '#' ) num_of_mines++;
        if ( spaces_mines[rows] == '#' ) num_of_mines++;
        if ( spaces_mines[rows + 1] == '#' ) num_of_mines++;
    }
    else if ( (user_move_p1 - 1) == (num_rows - rows) ) { // Check bottom left corner
        if ( spaces_mines[(num_rows - rows) + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(num_rows - (rows * 2))] == '#' ) num_of_mines++;
        if ( spaces_mines[(num_rows - (rows * 2)) + 1] == '#' ) num_of_mines++;
    } 
    // Start checking for edges
    else if ( user_move_p1 % rows == 0 ) { // Check if it is on the right most edge
        if ( spaces_mines[user_move - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) - 1] == '#')  num_of_mines++;
        if ( spaces_mines[(user_move + rows)] == '#') num_of_mines++;
        if ( spaces_mines[(user_move + rows) - 1] == '#' ) num_of_mines++;
    }
    else if ( (user_move_p1 - 1) % rows == 0 ) { // Check if it is on the left most edge
        if ( spaces_mines[user_move + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) + 1] == '#')  num_of_mines++;
        if ( spaces_mines[(user_move + rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows) + 1] == '#' ) num_of_mines++;
    }
    else if ( user_move_p1 <= rows ) { // Check if it is on the top most edge
        if ( spaces_mines[user_move - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[user_move + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows) + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows) - 1] == '#' ) num_of_mines++;
    }
    else if (user_move_p1 >= (num_rows - rows) ) { // Check if it is on the bottom most edge
        if ( spaces_mines[user_move - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[user_move + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) - 1] == '#' ) num_of_mines++;
    }
    else { // Anything that's not on the edge
        if ( spaces_mines[user_move - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[user_move + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move - rows) - 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows)] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows) + 1] == '#' ) num_of_mines++;
        if ( spaces_mines[(user_move + rows) - 1] == '#' ) num_of_mines++;
    }

    return num_of_mines;
}


bool isDead( std::vector<char> &spaces, std::vector<char> spaces_mines, int num_rows, int &points, int user_move, int rows ) {
    // Checks if the user has hit a mine
    int mine_count = 0;

    for (int i = 0; i < num_rows; i++) {
        if (spaces[i] == 'X' && spaces_mines[i] == '#') {
            return true;
        }
    }
    mine_count = searchAmountOfMines(spaces_mines, user_move, rows, num_rows);
    points++;

    // Change from int to char
    char mine_count_char;
    switch(mine_count) {
        case 0:
            mine_count_char = '0';
            break;
        case 1:
            mine_count_char = '1';
            break;
        case 2:
            mine_count_char = '2';
            break;
        case 3:
            mine_count_char = '3';
            break;
        case 4:
            mine_count_char = '4';
            break;
        case 5:
            mine_count_char = '5';
            break;
        case 6:
            mine_count_char = '6';
            break;
        case 7:
            mine_count_char = '6';
            break;
        case 8:
            mine_count_char = '6';
            break;
    default:
        std::cout << "Error!" << std::endl;
        return -1;
    }

    spaces[user_move] = mine_count_char;

    return false;
}


bool checkWin() {

    return false;
}


int moveToInt( std::string space_to_move, int rows ) {
    char starting_char = 'A';
    int user_move;
    int check_col = 1;
    int check_row = 1;

    // Check the column the user inputted
    for ( int i = 1; i <= rows; i++ ) {
        check_col = i;
        if ( space_to_move[0] == starting_char ) break;
        else starting_char++;
    }

    // Check the row the user inputted
    starting_char = 'a';
    for ( int i = 1; i <= rows; i++ ) {
        check_row = i;
        if  ( space_to_move[1] == starting_char ) break;
        else starting_char++;
    }

    user_move = ( (check_row * rows) - (rows - check_col) ) - 1;

    return user_move;
}


int getUserMove( int rows, std::vector<char> &spaces ) {
    std::string space_to_move;
    int user_move;

    do {
        std::cout << "Enter your move by letters(Aa, Gc, Be, etc.): ";
        std::cin >> space_to_move;
    } while ( (space_to_move[0] > (65 + rows) || space_to_move[1] > (97 + rows)) 
            || (space_to_move[0] < 65 || space_to_move[1] < 97) );

    user_move = moveToInt(space_to_move, rows);
    spaces[user_move] = 'X';

    return user_move;
}