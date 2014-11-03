/*
 * ComputerPlayer.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: williamhooper
 */

#include "ComputerPlayer.h"
#include <time.h>

ComputerPlayer::ComputerPlayer(string name, Board::Pieces piece,
		Board & board) :
		Player(name, piece, board) {
            srand( static_cast<unsigned int>(time(NULL)));
           // srand(time(NULL));
            //srand( static_cast<unsigned int>(time(NULL)));
}


ComputerPlayer::~ComputerPlayer() {
	// TODO Auto-generated destructor stub
}

void ComputerPlayer::nextMove(){
    /*
     * This while statement keeps looping through until
     * a valid move is made
     */
    
    while(true)
    {
        
        //decide whether to use O or X
        char s = 0;
        if (this -> piece == 0) {
            s = 'X';
        }
        else if(this -> piece == 1){
            s = 'O';
        }
        
        
        //use random numbers to generate the move
        int rowRand = rand() % 3;
        int colRand = rand() % 3;
        //int rowRand = 0;
        //int colRand = 0;
        
        
        
        if(board.isEmpty(rowRand, colRand) == true)
        {
            /*
             * If everything is good:
             * set the piece and output the board
             */
            
            board.set(rowRand, colRand, this->piece);
            
            //break;
            return;
        }
        
        /*
         * If everything is not good then
         * output error message, display the board, and start over
         */
        
        else
        {
            
            
            //cerr << "trying another random board location \n";
            
            //cout << board << endl;
            
        }
    
        
        
    }

}
