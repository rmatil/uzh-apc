//
//  my_player.cpp
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "my_player.h"

int my_player::play(const my_playfield &pField) {
	
	int column;
	std::cout << "Type in a column where your stone should be placed: " << std::endl;
	std::cin >> column;
	return column;
}