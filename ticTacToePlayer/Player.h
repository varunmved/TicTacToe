/*
 * Player.h
 *
 *  Created on: Apr 22, 2014
 *      Author: williamhooper
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Board.h"

using namespace std;

class Player {
public:
	Player(string name, Board::Pieces piece, Board &board);
	virtual ~Player();
    
	/**
	 * Play this player's next move
	 */
	virtual void nextMove() = 0;
    
	/**
	 * Get the player's piece
	 */
	Board::Pieces getPiece() const {
		return piece;
	}
    
	/**
	 * Output board to an output stream
	 */
	friend ostream& operator<<(ostream& out, const Player& b);
    
protected:
	string name;
	Board::Pieces piece;
	Board &board;
};

#endif /* PLAYER_H_ */
