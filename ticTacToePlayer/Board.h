/*
 * Board.h
 *
 *  Created on: Apr 22, 2014
 *      Author: williamhooper
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string>

using namespace std;

#define BoardSize 3

class Board {
public:
	Board();
	virtual ~Board();
    
	enum Pieces {
		X , O, Empty
	};
    
	/**
	 * Return true if the board position is empty
	 */
	bool isEmpty(int row, int col) const;
    
	/**
	 * Return true if the piece is Empty
	 */
	bool isEmpty(Pieces value) const;
    
	/**
	 * Return the piece at the board position
	 */
	Pieces pieceAt(int row, int col) const;
    
	/**
	 * Return the piece that is the winner, else return Empty
	 */
	Pieces winner() const;
    
	/**
	 * Return the row/column size
	 */
	int getBoardSize() const;
    
	/**
	 * Clear the board
	 */
	void clear();
    
	/**
	 * Return true if the board is full
	 */
	bool isFull() const;
    
	/**
	 * Set a board position with a piece
	 */
	void set(int row, int col, Pieces p);
    
	/**
	 * Output board to an output stream
	 */
	friend ostream& operator<<(ostream& out, const Board& b);
    
private:
	Pieces board[BoardSize][BoardSize];
};

#endif /* BOARD_H_ */
