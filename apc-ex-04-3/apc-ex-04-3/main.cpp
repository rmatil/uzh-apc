//
//  main.cpp
//  apc-ex-03-4
//
//  Created by Raphael Matile on 28.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "RPN.h"
#include "RPN.cpp"

int main(int argc, const char * argv[])
{
    // int
	RPN<int> rpn = RPN<int>("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-3/apc-ex-04-3/stack-int.txt");
	rpn.run();
	
    // Fraction
    std::cout << "------------------------------------" << std::endl;
    std::cout << "now you are using rpn with Fractions" << std::endl;
	RPN<Fraction> rpn2 = RPN<Fraction>("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-3/apc-ex-04-3/stack.txt");
	rpn2.run();
	
    return 0;
}

