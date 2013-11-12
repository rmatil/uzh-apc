//
//  main.cpp
//  apc-ex-04-4
//
//  Created by Raphael Matile on 31.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "combineops_t.h"

struct division: public std::binary_function<double, double, double> {
public:
    double operator()(const float &a, const float &b) {
        return (a/b);
    }
};

struct f1: public std::unary_function<double, double> {
public:
    double operator()(const int &x) {
        return (pow(x, 3));
    }
};

struct f2: public std::unary_function<double, double> {
public:
    double operator()(const int &x) {
        return (pow(x+3, 2));
    }
};



int main() {
	
    // calculating a division of two functions:
    // function f1: x^3
    // function f2: (x+3)^2
    
    // class combineops combines two unary functions (functions with only one argument).
    // resulttype is a binary function with f1(x) and f2(x) as arguments.
    
    // Op1: f1
    // Op2: f2
    // BinOp: f1/f2
    
    division divOb;
    f1 function1;
    f2 function2;
    combineops_t<division, f1, f2> result(divOb, function1, function2);
    
    for (double d = 0.0; d<9; d+=2) {
        std::cout << "(" << d << "^3) / ([" << d << "+3]^2), result: " << result(d) << std::endl;
    }
	
	
	return 0;
}