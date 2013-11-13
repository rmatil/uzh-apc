//
//  declaration-definition.cpp
//  apc-ex-02-1
//
//  Created by Raphael Matile on 13/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "declaration-definition.h"

int count = 1; // declaration and initialising of a new variable

char *name = "It's me."; // declaration and initalising of a new pointer. Compiler knows where to point at.

char *prog[] = {"echo", "hello", "world!", NULL }; // declaration and initalising of a new array. Compiler knows were to point at.

void swap(int &a, int &b) { // implementation of a method. Requires already defined integers as arguments
    int c = a;
    a = b;
    b = c;
}

