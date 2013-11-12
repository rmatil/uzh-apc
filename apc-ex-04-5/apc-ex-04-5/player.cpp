//
//  player.cpp
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "player.h"

template<typename F>
int player<F>::play(const F &pField) {
	
	int column;
	std::cout << "Type in a column where your stone should be placed: " << std::endl;
	std::cin >> column;
	
	
	return column;
}