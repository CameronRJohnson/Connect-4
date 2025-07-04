#include "game.h"
#include <iostream>

Game::Game() : board(), player1("Player 1", 1), player2("Player 2", 2), currentPlayer(1) {}

void Game::start() {
    std::cout << "Starting Connect 4!" << std::endl;
    int winner = 0;
    int turn = 1;
    // Check to see if the board is full
    while (!board.isFull() && winner == 0) {
        board.display();
        Player current = (turn % 2 == 1) ? player1 : player2;
        int col;
        std::cout << current.getName() << " (" << (current.getId() == 1 ? 'X' : 'O') << ") - Choose a column (1-7): ";
        std::cin >> col;
        // Check to see if the player move is valid
        if (col < 1 || col > 7) {
            std::cout << "Invalid column. Try again." << std::endl;
            continue;
        }
        if (!board.makeMove(col - 1, current.getId())) {
            std::cout << "Column full. Try another column." << std::endl;
            continue;
        }
        // Check to see if the player won
        winner = board.checkWin();
        ++turn;
    }
    board.display();
    if (winner) {
        std::cout << (winner == 1 ? player1.getName() : player2.getName()) << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}