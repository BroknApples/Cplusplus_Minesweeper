#include <iostream>
#include <vector>

void drawBoard( std::vector<char> spaces, int rows ) {
    int rows_factor = (rows - 1);
    char row_counter = 'A';
    char col_counter = 'A';
    

    std::cout << "  "; // Output the 'dead' space(where the row and column overlap)
    for ( int i = 0; i < rows; i++ ) {
        std::cout << row_counter << "  ";
        row_counter++;
    }
    std::cout << "\n";
    
    std::cout << col_counter << "  ";
    for ( int i = 0; i <= (rows * rows); i++ ) {
        if ( (i <= rows * (rows - rows_factor)) ) {
            std::cout << spaces[i] << " ";
        }
        else {
            rows_factor--;
            std::cout << "\n";
            std::cout << col_counter << "  ";
            col_counter++;
        }
    }
}