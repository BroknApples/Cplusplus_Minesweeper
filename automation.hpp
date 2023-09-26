#include <iostream>
#include <vector>

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


bool dfs( std::vector<char> spaces_mines, int user_move, int rows ) {
    if (user_move % rows == 0) {
    }

    return false;
}


int addPoint( int points ) {
    return points + 1;
}


bool isDead( std::vector<char> spaces, std::vector<char> spaces_mines, int num_rows, int &points, int user_move, int rows ) {
    // Checks if the user has hit a mine
    for (int i = 0; i < num_rows; i++) {
        if (spaces[i] == 'X' && spaces_mines[i] == '#') {
            return true;
        }
        else {
            dfs(spaces_mines, user_move, rows);
            points = addPoint(points);
        }
    }

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

    std::cout << user_move << "\n";
    return user_move;
}


int getUserMove( int rows ) {
    std::string space_to_move;
    int user_move;

    std::cout << "Enter your move by letters(Aa, Gc, Be, etc.): ";
    std::cin >> space_to_move;

    user_move = moveToInt(space_to_move, rows);

    return user_move;
}