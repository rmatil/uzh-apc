//
//  ai.h
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__ai__
#define __apc_ex_06_4__ai__

#include <iostream>
#include "player.h"
#include "my_playfield.h"
#include <ctime>

class ai : player {
public:

	int play(const my_playfield &field);
    int play(const playfield &field) { return 0; } // override the virtual function of super class player
    
private:
    int determinePlayerRole(my_playfield pField);
    
    int playNext(int enemyPlayer, my_playfield pField);
    int playerRole = 0;
    
    bool isDiagonalAndLeftEmpty(my_playfield pField, int pColumn, int pPlayer);
    bool isDiagonalAndRightEmpty(my_playfield pField, int pColumn, int pPlayer);
};

#endif /* defined(__apc_ex_06_4__ai__) */
