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
#include "Fraction.h"

int main(int argc, const char * argv[])
{

	//RPN<int> rpn = RPN<int>();
	//rpn.run();
	
	//RPN<float> rpn = RPN<float>();
	//rpn.run();
	
	RPN<Fraction> rpn = RPN<Fraction>();
	rpn.run();
	
    return 0;
}

