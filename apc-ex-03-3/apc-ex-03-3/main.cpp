//
//  main.cpp
//  apc-ex-02-3
//
//  Created by Raphael Matile on 12.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "RPN.h"


int main(int argc, const char * argv[])
{
    // Note: Xcode is using absolute paths to files. If you are not using Xcode you may have to change
    // this path...
	RPN rpn = RPN("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-03-3/apc-ex-03-3/stack.txt");
	rpn.run();

    return 0;
}

	

