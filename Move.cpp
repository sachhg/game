#include "Errors.h"
#include "Move.h"
#include <sstream> //for istringstream to be used as a parser
#include <iostream>


Move::Move(const std::string& input){

    std::istringstream parser (input);
    int moveNum;
    char playerCode;
    char rowCode;
    int columnCode;
    bool isComment = false;
    std::string comment;

    if (parser.peek() == '+' || parser.peek() == '-'){
        throw ParseError("Parse error. (no signs allowed)");
        exit(1);
    }

    if (isspace(parser.peek())){
        throw ParseError("Parse error. (space cannot lead)");
        exit(1);
    }

    if (parser.peek() == '0'){

        throw ParseError("Parse error. (Must enter move number as a single digit)");
        exit(1);
    }

    parser >> moveNum;

    if (!isspace(parser.peek())){
        throw ParseError("Parse error. (no space)");
        exit(1);
    }

    parser >> playerCode;

    if (!isspace(parser.peek())){
        throw ParseError("Parse error. (no space)");
        exit(1);
    }

    parser >> rowCode;

    if (parser.peek() == '+' || parser.peek() == '-'){
        throw ParseError("Parse error. (no signs allowed)");
        exit(1);
    }

    if (parser.peek() == '0'){
        throw ParseError("Parse error. (must enter column num as a single digit)");
        exit(1);
    }

    if (isspace(parser.peek())){
        throw ParseError("Parse error. (no space)");
        exit(1);
    }


    parser >> columnCode;

    if (parser.peek() == '#'){

        isComment = true;
    }

    if (isComment){
    
        if (!isspace(parser.peek())){

            throw ParseError("Parse error. (no space before comment)");
            exit(1);

        }

    }

    parser.get();
    parser.get();
    parser >> comment;

    if (parser.peek() != EOF && parser.peek() != '\n'){
        throw ParseError("Parse error. (comment must be one word)");
        exit(1);
    }

    //std::cout << "DEBUGGING MOVE PARSER: Checking variable initialization.\nThis is move number: " << moveNum << std::endl << "Player Code: " << playerCode << std::endl << "Row: " << rowCode << std::endl << "Column: " << columnCode << std::endl << "Comment: " << comment << std::endl;


    if (!(moveNum >= 1 && moveNum <= 9)){
        throw ParseError("Parse error. (moveNum)");
        exit(1);
    }//checks that the move number is within 1 and 9, inclusive

    playerCode = toupper(playerCode);

    if (playerCode != 'X' && playerCode != 'O'){
        throw ParseError("Parse error. (pCode)");
        exit(1);
    }//checks that the playerCode is X or O

    rowCode = toupper(rowCode);

    if (rowCode != 'A' && rowCode != 'B' && rowCode != 'C'){
        throw ParseError("Parse error. (row)");
        exit(1);
    }//checks that the row code is A B or C
    
    if (columnCode != 1 && columnCode != 2 && columnCode != 3){
        throw ParseError("Parse error. (col)");
        exit(1);
    }//checks that the column code is 1 2 or 3
    
    //the lines below initialize all private class elements
    number = moveNum;
    player = playerCode;
    row = rowCode;
    column = columnCode;

    return;

}

std::string Move::to_string() const{

    std::string result = "";

    result += std::to_string(number);
    result += " ";
    result += player;
    result += " ";
    result += static_cast<char>(row);
    result += std::to_string(column);

    return result;

}


//test
// Space for implementing Move functions.
