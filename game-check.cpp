#include "Board.h"
#include "Errors.h"
#include "Move.h"

#include <iostream>
#include <sstream>
#include <vector>

int main() {
    try{
        Board board;
        std::string input, line;
        int moveNum = 0;
        char player;
        char row;
        int column;
        int counter = 1;
        std::vector<char> turns(9, ' ');
        bool gameOver = false;
        char winner;

        while (std::getline(std::cin, input)){

            Move move(input);

            std::string line = move.to_string();

            std::istringstream parser(line);
            parser >> moveNum >> player >> row >> column;
        
            if (moveNum != counter){
                throw InvalidMove("Invalid move.");
                exit(2);
            }
            counter++;

            turns[moveNum - 1] = player;

            if (moveNum > 1 && (turns[moveNum - 2] == turns[moveNum - 1])){
                throw InvalidMove("Invalid move.");
                exit(2);
            }

            if (gameOver){
                throw InvalidMove("Invalid move.");
                exit(2);
            }


            std::string position = "";
            position += row;
            position += std::to_string(column);

            //std::cout << "position: " << position << std::endl;
            //std::cout << "player: " << player << std::endl;

            board.makeMove(position, player);

            if (board.checkWin(player)){
                gameOver = true;
                winner = player;
            }

            //board.display();       


        }

        if (gameOver){
            std::cout << "Game over: " << winner << " wins.\n";
            return 0;
        } else {

            if (turns[0] == ' '){
                std::cout << "Game in progress: New game.\n";
                return 0;
            }

            if (moveNum == 9){
                std::cout << "Game over: Draw.\n";
                return 0;
            }

            if (turns[moveNum - 1] == 'X'){
                std::cout << "Game in progress: O's turn.\n";
                return 0;
            } else {
                std::cout << "Game in progress: X's turn.\n";
                return 0;
            }
        }


    }
    catch(const ParseError& e){
        std::cout << "Parse error.\n";
        return 1;
    }
    catch(const InvalidMove& e){
        std::cout << "Invalid move.\n";
        return 2;
    }
}
