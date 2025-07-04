#include "board.h"
#include <iostream>

// Game board to be referenced when rebuilding
Board::Board() : grid(6, std::vector<int>(7, 0)) {}

// Create the top Layer
// Create the game board
// Create bottom layer
void Board::display() const {
    std::cout << "\n   1   2   3   4   5   6   7" << std::endl;
    std::cout << " +---+---+---+---+---+---+---+" << std::endl;
    for (int row = 0; row < 6; ++row) {
        std::cout << " |";
        for (int col = 0; col < 7; ++col) {
            char c = ' ';
            if (grid[row][col] == 1) c = 'X';
            else if (grid[row][col] == 2) c = 'O';
            std::cout << " " << c << " |";
        }
        std::cout << std::endl;
        std::cout << " +---+---+---+---+---+---+---+" << std::endl;
    }
}

// From row 0 up check if empty then place
bool Board::makeMove(int column, int player) {
    for (int row = 5; row >= 0; --row) {
        if (grid[row][column] == 0) {
            grid[row][column] = player;
            return true;
        }
    }
    return false;
}

// Check to see the lowest column value
// If 0 return false
bool Board::isFull() const {
    for (int col = 0; col < 7; ++col) {
        if (grid[0][col] == 0) return false;
    }
    return true;
}

int Board::checkWin() const {
    // Horizontal
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            int p = grid[row][col];
            if (p && p == grid[row][col+1] && p == grid[row][col+2] && p == grid[row][col+3])
                return p;
        }
    }
    // Vertical
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            int p = grid[row][col];
            if (p && p == grid[row+1][col] && p == grid[row+2][col] && p == grid[row+3][col])
                return p;
        }
    }
    // Diagonal (down-right)
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            int p = grid[row][col];
            if (p && p == grid[row+1][col+1] && p == grid[row+2][col+2] && p == grid[row+3][col+3])
                return p;
        }
    }
    // Diagonal (up-right)
    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            int p = grid[row][col];
            if (p && p == grid[row-1][col+1] && p == grid[row-2][col+2] && p == grid[row-3][col+3])
                return p;
        }
    }
    return 0;
}