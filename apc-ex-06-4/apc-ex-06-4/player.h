//
//  player.h
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__player__
#define __apc_ex_06_4__player__

#include <iostream>
#include "playfield.h"

class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {}
};

#endif /* defined(__apc_ex_06_4__player__) */
