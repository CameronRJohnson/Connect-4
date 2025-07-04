#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    void display() const;
    bool makeMove(int column, int player);
    bool isFull() const;
    int checkWin() const;
private:
    std::vector<std::vector<int>> grid;
};

#endif
