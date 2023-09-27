#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>


void drawBoard( std::vector<char> spaces, int rows, int num_rows ) {
    // Outputs the board after a turn
    int rows_factor = (rows - 1);
    char col_counter = 'A';
    char row_counter = 'a';
    

    std::cout << "  "; // Output the 'dead' space(where the row and column overlap)
    for ( int i = 0; i < rows; i++ ) {
        std::cout << col_counter << "  ";
        col_counter++;
    }
    std::cout << "\n";
    
    std::cout << row_counter << " ";
    row_counter++;
    for ( int i = 0; i < num_rows; i++ ) {
        if ( i <= ((rows * (rows - rows_factor)) - 1) ) {
            std::cout << spaces[i] << "  ";
        }
        else { // Output new line with the statement that failed to output on the previous line
            rows_factor--;
            std::cout << "\n";
            std::cout << row_counter << " ";
            std::cout << spaces[i] << "  ";
            row_counter++;
        }
    }
    std::cout << std::endl;
}

void createMines(std::vector<char> &spaces_mines, int rows, int num_rows ) {
    // Function that will randomly create mines in the mine array
    srand(time(NULL));

    int i = 0;
    int num_differ = rand() % (rows / 2);
    int is_pos_or_neg = rand() % 2 + 1;
    int random_num_ratio;


    if (is_pos_or_neg == 1) {
        random_num_ratio = (num_rows * 0.30) + num_differ;
    }
    else {
        random_num_ratio = (num_rows * 0.30) - num_differ;
    }
    
    while (i < random_num_ratio) {
        int random_mine_space = rand() % num_rows + 1;
        spaces_mines[random_mine_space] = '#';

        i++;
    }

}