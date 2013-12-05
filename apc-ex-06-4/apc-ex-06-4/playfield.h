//
//  playfield.h
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_06_4__playfield__
#define __apc_ex_06_4__playfield__

class playfield {
public:
    // the size of the field
    const static int width=7;
    const static int height=6;
    
    // the elements stored at individual field positions
    const static int none=0;
    const static int player1=1;
    const static int player2=2;
    
    // returns the stone (none/player1/player2) at the position
    // 0 <= x <= width
    // 0 <= y <= height
    // stoneat(0,0) ................ top left
    // stoneat(width-1,height-1) ... bottom right
    // if we insert a stone in a new game in column i,
    // it lands at (i,height-1)
    virtual int stoneat(int x, int y) const = 0;
    virtual ~playfield() {}
}; 


#endif /* defined(__apc_ex_06_4__playfield__) */
