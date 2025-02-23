#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

class Board{

    private:
        char A1, A2, A3;
        char B1, B2, B3;
        char C1, C2, C3;

    public:

        Board();

        void makeMove(std::string position, char player);

        bool isCellEmpty(std::string position);

        void display();

        bool checkWin(char player);

        
};

#endif
