/*
 * Board.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: williamhooper
 */


//Varun Ved

#include "Board.h"

Board::Board()
{
    clear();
}
// TODO Auto-generated constructor stub

/*
 * Determine whether to board is empty or not
 * (given a position)
 */

bool Board::isEmpty(int myRow, int myCol) const
{
    if(pieceAt(myRow, myCol) == Empty)
    {
        return true;
    }
    else return false;
}


/*
 * Determine whether to board is empty or not
 * (given a piece)
 */
bool Board::isEmpty(Pieces myValue) const
{
    if (myValue == Empty)
        return true;
    else return false;
}


/*
 * Return the piece at a row,col
 */

Board::Pieces Board::pieceAt(int myRow, int myCol) const
{
    
    if (board[myRow][myCol] == X)
        return X;
    else if(board[myRow][myCol] == O)
        return O;
    else return Empty;
}


/*
 * Return the piece of the winner
 * I did this by checking each possible winning row, col, diagonal
 * to see if they have the same piece, and to make sure that piece isn't empty
 * if that's true, then that piece is the winner
 */


Board::Pieces Board::winner() const
{

    if((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && (board[0][0] != Empty)) return board[0][0];
    if((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][0] != Empty)) return board[1][0];
    if((board[2][0] == board[2][1]) && ( board[2][1] == board[2][2]) && (board[2][0] != Empty)) return board[2][0];
    if((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[0][0] != Empty)) return board[0][0];
    if((board[0][1] == board[1][1]) && ( board[1][1] == board[2][1]) && (board[1][1] != Empty)) return board[1][1];
    if((board[0][2] == board[1][2]) && ( board[1][2] == board[2][2]) && (board[1][2] != Empty)) return board[1][2];
    if((board[0][0] == board[1][1]) &&(board[1][1] == board[2][2]) && (board[1][1] != Empty)) return board[1][1];
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != Empty)) return board[1][1];
    else return Empty;
    
}

//return the boardsize

int Board::getBoardSize() const
{
    return BoardSize;
}


/*
 * Clear the board
 * I did this by creating a for loop that goes through
 * each piece and sets the piece = empty
 */
void Board::clear()
{
    for(int i = 0; i < BoardSize ; i++)
    {
        for (int j =0; j < BoardSize; j++) {
            
            board[i][j] = Empty;//nope
            
        }
    }
}


/*
 * Check if the board is full
 * I did this by creating a for loop and testing each row and col,
 * if any of the pieces were empty, it equals false
 */

bool Board::isFull()const
{
    for(int i = 0 ; i < BoardSize ; i++)
    {
        for (int j = 0; j < BoardSize; j++) {
            
            if(isEmpty(i, j) == true)
                return false;
        }
    }
    return true;
}

/*
 * The set function places the piece at the row and col which is
 * passed to the function
 */

void Board::set(int myRow, int myCol, Pieces myP)
{
    board[myRow][myCol]= myP;
    //cout << b;
}

/*
 * Output the board to an output stream
 * A set of for loops is used to first output the =======
 * creating the board
 * The next set for loop out puts each piece
 * A switch statement decides whether to print X O or a default - for empty
 */
ostream& operator<<(ostream& out, const Board& b)
{
    for(int row =0; row < 3; row++)
    {
        for (int i=0; i < 3; i++) {
            out << "==";
            
        }
        out << "=" <<endl;
        for(int col=0 ; col < 3; col++)
        {
            switch(b.board[row][col])
            {
                case Board::X:
                    out << " X";
                    break;
                case Board::O:
                    out <<  " O";
                    break;
                    
                default:
                    out << " -";
                    break;
            }
            
        }
        out  << endl;
    }
    out << "=======";
    return out;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}


/*
 0,0| 0,1 | 0,2
 ---|-----|----
 1,0| 1,1 | 1,2
 ---|-----|----
 2,0| 2,1 | 2,2
 
 X  |  X  |  X
 ----|-----|----
 X  |  X  |  X
 ----|-----|----
 X  |  X  |  X
 
 
 */