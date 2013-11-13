//
//  declaration-definition.h
//  apc-ex-02-1
//
//  Created by Raphael Matile on 13/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_02_1__declaration_definition__
#define __apc_ex_02_1__declaration_definition__

#include <iostream>

char ch; // declaration of a new variable

string s; // declaration of a new variable

extern int error_number; // extern tells the compiler that the variable is defined somewhere else, so it doesn't complain about it being undefined

static double sq(double); // static method declaration: compiler knows about method name and argument type for linkage

const double pi = 3.5 // const variable

struct fraction { // declaration of a new struct
    int c;
    int d;
};

extern "C" void c_swap(int *a, int *b); // c++ is using method name and information about the arguments -> using c linkage of compiler
                                        // -> functions can not be overloaded in C ->
                                        // C++ compiler does not add argument/paramter type information to the name used for linkage

double sqrt(double); // compiler knows method name and argument type used for linkage

namespace NS { // declaring a integer variable only in the scope of the namespace NS
    int a;
}

struct user; // declaring a new struct. 


#endif /* defined(__apc_ex_02_1__declaration_definition__) */
