#include <iostream>
#include <vector>

int intro() {
    // Returns number of spaces utilized in the game
    int rows;
    do {
        std::cout << "Enter the nummber of rows you would like to play with(5 - 26): ";
        std::cin >> rows;
    } while(rows < 5 || rows > 26);

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
    // Checks if the user has hit a mine


    return false;
}

int addPoint( /**/ ) {
    // If the user did not hit a mine, add a point


    return 0;
}