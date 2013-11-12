//
//  player.h
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_04_5__player__
#define __apc_ex_04_5__player__

#include "playfield.h"
#include <iostream>

template<typename F>
class player {
public:
	// returns the column where the player decides to throw in his
	// stone
	// F is the playfield which may be any playfield implementing
	// the stoneat method, if you expect a different class because
	// you need methods to verify whether the opponent can win,
	// copy the field into the class that you expect.
	int play(const F &field);
};

#endif /* defined(__apc_ex_04_5__player__) */
