//
//  main.cpp
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "playfield.h"
#include "player.h"
#include "player.cpp"
#include "game.h"
#include "game.cpp"


int main(int argc, const char * argv[])
{	
	player<playfield> pl1;
	player<playfield> pl2;
	playfield field;
	
	game<player<playfield>, player<playfield> > g(pl1, pl2);
	g.run(field);
	
	
	
    return 0;
}

