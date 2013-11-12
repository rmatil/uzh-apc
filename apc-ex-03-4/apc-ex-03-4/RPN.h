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
#include "math.h"

template<typename T> class RPN {
private:
	std::string input_;
	std::vector<T> stack_;
	typename std::vector<T>::iterator end_;
	T first_;
	T second_;

	
public:
	RPN() {
		end_ = stack_.end();
	};
	~RPN() {};
	
	void add();
	void remove();
	
	void compute_min();
	T mymin(T a, T b);
	
	void addition();
	void subtraction();
	void mulitplication();
	void division();
	void arctan();
	
	void printRes(const T pRes);
	void printStack();
	inline bool isEmpty() { return stack_.empty(); }
	inline bool tooShort() { return (stack_.size() < 2); }
	
	void run();
};




#endif /* defined(__apc_ex_03_3__RPN__) */
