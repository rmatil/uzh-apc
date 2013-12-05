//
//  main.cpp
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "my_player.h"
#include "game.h"
#include "game.cpp"
#include "ai.h"

int main(int argc, const char * argv[])
{
    
	my_player pl1;
	//my_player pl2;
    ai pl2;
    ai pl3;
	my_playfield field;
    
    game<my_player, ai> game(pl1, pl2);
    //game<ai, ai> game(pl2, pl3);
    game.run(field);

    
    
    return 0;
}

