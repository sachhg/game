#include "Errors.h"
#include "Board.h"

#include <iostream>


Board::Board(){

    A1 = ' ', A2 = ' ', A3 = ' ';
    B1 = ' ', B2 = ' ', B3 = ' ';
    C1 = ' ', C2 = ' ', C3 = ' ';

}

void Board::display() {
    std::cout << " " << A1 << " | " << A2 << " | " << A3 << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << B1 << " | " << B2 << " | " << B3 << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << C1 << " | " << C2 << " | " << C3 << "\n";
}


bool Board::isCellEmpty(std::string position){

    if (position == "A1"){
        return (A1 == ' ');
    }
    else if (position == "A2"){
        return (A2 == ' ');
    }
    else if (position == "A3"){
        return (A3 == ' ');
    }
    else if (position == "B1"){
        return (B1 == ' ');
    }
    else if (position == "B2"){
        return (B2 == ' ');
    }
    else if (position == "B3"){
        return (B3 == ' ');
    }
    else if (position == "C1"){
        return (C1 == ' ');
    }
    else if (position == "C2"){
        return (C2 == ' ');
    }
    else if (position == "C3"){
        return (C3 == ' ');
    }
    else {
        return false;
    }
}


bool Board::checkWin(char player){

    if ( (A1 == player && B1 == player && C1 == player) || (A2 == player && B2 == player && C2 == player) || (A3 == player && B3 == player && C3 == player) ) {

        return true;

    }

    if ( (A1 == player && A2 == player && A3 == player) || (B1 == player && B2 == player && B3 == player) || (C1 == player && C2 == player && C3 == player) ){

        return true;

    }

    if ( (A1 == player && B2 == player && C3 == player) || (A3 == player && B2 == player && C1 == player) ){

        return true;

    }
    
    return false;

}


void Board::makeMove(std::string position, char player){

    if (isCellEmpty(position) == false){

        throw InvalidMove("Invalid move.");
        exit(2);
    }

    if (position == "A1"){
        A1 = player;
        return;
    }
    else if (position == "A2"){
        A2 = player;
        return;
    }
    else if (position == "A3"){
        A3 = player;
        return;
    }
    else if (position == "B1"){
        B1 = player;
        return;
    }
    else if (position == "B2"){
        B2 = player;
        return;
    }
    else if (position == "B3"){
        B3 = player;
        return;
    }
    else if (position == "C1"){
        C1 = player;
        return;
    }
    else if (position == "C2"){
        C2 = player;
        return;
    }
    else if (position == "C3"){
        C3 = player;
        return;
    }

}
