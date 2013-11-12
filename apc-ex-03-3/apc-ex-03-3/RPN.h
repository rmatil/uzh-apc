//
//  RPN.h
//  apc-ex-03-3
//
//  Created by Raphael Matile on 28.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_03_3__RPN__
#define __apc_ex_03_3__RPN__

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>     /* atoi */
#include "PVector.cpp"
#include "PVector.h"

class RPN {
private:
	std::string input_;
	PVector<float> pvector_stack_ = PVector<float>();
	
public:
	RPN(std::string pFilename) {
        pvector_stack_.setFilename(pFilename);
        
	};
	~RPN() {};
	void printUsage();
	void operate(const char* pOperation);
	void printStack();
	
	void run();
};




#endif /* defined(__apc_ex_03_3__RPN__) */
