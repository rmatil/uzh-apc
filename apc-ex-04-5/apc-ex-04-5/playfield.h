//
//  playfield.h
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_04_5__playfield__
#define __apc_ex_04_5__playfield__

#include <iostream>
#include <vector>

class playfield {
public:
	// the size of the field
	const static int width = 7;
	const static int height = 6;
	
	// these elements are used to indicate whether a given position
	// in the playing field is taken by a given player
	const static int none = 0;
	const static int player1 = 1;
	const static int player2 = 2;
	
	playfield();
	~playfield();
	
	// return the stone (none/player1/player2) at the position(x,y)
	// 0 <= x <= width
	// 0 <= y <= height
	// stoneat(0,0) ................ top left
	// stoneat(width-1,height-1) ... bottom right
	// if we insert a stone in a new game in column i,
	// it lands at (i,height-1)
	// implementation may be changed, interface not
	int stoneat(int pColumn, int pRow) const;
	
	// draws playfield to std::cout
	void drawPlayfield();
	
	// inserts a stone for player pPlayer at a desired column
	void insertStone(int pPlayer, int pColumn);
	
	// checks if player pPlayer is winning
	bool isWinning(int pPlayer);
	
	// clear playfield
	void clearPlayfield();
	
	// check if playfield is full
	bool isFull();
	
	// check if pColumn is full
	bool isFull(int pColumn);
	
protected:
	// the internal representation of the field.
	std::vector<std::vector<int> > rep;
};

#endif /* defined(__apc_ex_04_5__playfield__) */
