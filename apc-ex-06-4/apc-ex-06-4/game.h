//
//  game.h
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__game__
#define __apc_ex_06_4__game__

#include <iostream>
#include "my_playfield.h"
#include "my_player.h"

template<typename P1, typename P2>
class game {
public:
	game(P1 &pPlayer1, P2 &pPlayer2);
	~game() {};
	void run(my_playfield &pField);

private:
	my_playfield playField;
	bool isRunning = false;
	P1 player1;
	P2 player2;
};

#endif /* defined(__apc_ex_06_4__game__) */
