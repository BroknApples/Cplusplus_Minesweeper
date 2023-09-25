#include <iostream>
#include <vector>

int intro() {
    // Returns number of spaces utilized in the game
    int rows;
    std::cout << "Enter the nummber of rows you would like to play with(1 - 26): ";
    std::cin >> rows;

    // Output a gamespace header
    for ( int i = 0; i < ((rows  - 4)+ (rows / 4)); i++ ) {
        std::cout << "*";
    }
    std::cout << "WELCOME TO MINESWEEPER";
     for ( int i = 0; i < ((rows  - 4)+ (rows / 4)); i++ ) {
        std::cout << "*";
    }
    std::cout << std::endl;
    return rows;
}

bool isDead( std::vector<char> spaces, std::vector<char> spaces_mines ) {

    return false;
}

int addPoint( /**/ ) {

    return 0;
}