//
//  my_plafield.h
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__my_plafield__
#define __apc_ex_06_4__my_plafield__

#include <iostream>
#include <vector>
#include "playfield.h"

class my_playfield : public playfield {
public:
    
    my_playfield();
	virtual ~my_playfield();
	
	// return the stone (none/player1/player2) at the position(x,y)
	// 0 <= x <= width
	// 0 <= y <= height
	// stoneat(0,0) ................ top left
	// stoneat(width-1,height-1) ... bottom right
	// if we insert a stone in a new game in column i,
	// it lands at (i,height-1)
	// implementation may be changed, interface not
	virtual int stoneat(int pColumn, int pRow) const;
	
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

#endif /* defined(__apc_ex_06_4__my_plafield__) */
