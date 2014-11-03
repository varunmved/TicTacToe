/*
 * TerminalPlayer.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: williamhooper
 */

#include "TerminalPlayer.h"

TerminalPlayer::TerminalPlayer(string name, Board::Pieces piece,
                               Board & board) :
Player(name, piece, board) {
	// TODO Auto-generated constructor stub
    
}

/*
 * This is my nextMove() function
 * it reads in the position of the piece
 * and places it on the board accordingly
 * it also checks for errors
 */

void TerminalPlayer::nextMove()
{
    /*
     * This while statement determines whether to display:
     * X or O
     */
    
    while(true)
    {
        char s = 0;
        //output a prompt
        if (this -> piece == 0) {
            s = 'X';
        }
        else if(this -> piece == 1){
            s = 'O';
        }
        
        cout << "\n" << s << " please make a move by entering a (row,col) \n";
        
        //initialize variables to use
        int myRow, myCol;
        
        //accept input
        cin >> myRow >> myCol;
        
        //check for errors and if the board is full
        if(myRow < 3 && myCol < 3 && board.isEmpty(myRow, myCol) == true)
        {
            /*
             * If everything is good:
             * set the piece and output the board
             */
             
            board.set(myRow, myCol, this->piece);
            break;
        }
        
        /*
         * If everything is not good then
         * output error message, display the board, and start over
         */
        
        else
        {
            cerr << "sorry that's not a valid location \n";
            cout << board;
            
        }
        
    }
    
}

TerminalPlayer::~TerminalPlayer() {
	// TODO Auto-generated destructor stub
}

