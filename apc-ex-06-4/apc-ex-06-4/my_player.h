//
//  my_player.h
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__my_player__
#define __apc_ex_06_4__my_player__

#include <iostream>
#include "player.h"
#include "my_playfield.h"

class my_player : public player {
public:
    int play(const playfield &field) { return 0; } // override the virtual function of super class player
    int play(const my_playfield &field);
    ~my_player() {}
};

#endif /* defined(__apc_ex_06_4__my_player__) */
