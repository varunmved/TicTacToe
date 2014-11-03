//
//  main.cpp
//  TicTacToe2
//
//  Created by Varun Ved on 4/29/14.
//  Copyright (c) 2014 Varun Ved. All rights reserved.
//
#include <iostream>
#include "Board.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"

//#include "Board.cpp"
int main(int argc, const char * argv[])
{
    /*
     ***** Terminal player implementation ******
     */
    
    //create a board, and create two players for X and O
    Board myBoard;
    TerminalPlayer playerA("A", Board::X, myBoard);
    ComputerPlayer playerB("B", Board::O, myBoard);
    
    
    //first clear the board and display it
    myBoard.clear();
    cout << myBoard << "\n" << endl;
    
    //Game loop
    while(myBoard.isFull() != true)
    {
        //get player A's next move
        cout << "Player A moves" << endl;
        playerA.nextMove();
        
        //output the board
        cout << myBoard << "\n" << endl;
        
        /* Check for a winner &
         * if no winner, then check if board is full
         */
        
        if(myBoard.winner() != Board::Empty && myBoard.isFull() == false)
        {
            //output winner
            cout << " And the winner is: " <<(myBoard.winner() == Board::X ? "X": "O");
            break;
            
        }
        
        //if board is full output the board and draw
        else if(myBoard.winner() == Board::Empty && myBoard.isFull() == true)
        {
            //output draw
            cout << "that's a draw!";
            break;
        }
        
        
        //get player B's next move
        cout << "Player B moves" << endl;
        playerB.nextMove();
        
        //output the board
        cout << myBoard << "\n"<< endl;
        
        
        /* Check for a winner &
         * if no winner, then check if board is full
         */
        
        if(myBoard.winner() != Board::Empty && myBoard.isFull() == false)
        {
            //output winner
            cout << " And the winner is: " <<(myBoard.winner() == Board::X ? "X": "O") << "\n";
            break;
            
        }
        
        //if board is full output the board and draw
        else if(myBoard.winner() == Board::Empty && myBoard.isFull() == true)
        {
            //output draw
            cout << "that's a draw!";
            break;
        }
        
        //goto start of game loop
        
        
    }
    
    
    
}

