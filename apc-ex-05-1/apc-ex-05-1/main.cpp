//
//  main.cpp
//  apc-ex-05-1
//
//  Created by Raphael Matile on 10.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "variant1.h"
#include "variant2.h"

template<typename T>
void calculate(T &ob) {
    ob.setWidth(5);
    ob.setHeight(4);
    std::cout << "area: " << ob.getHeight()*ob.getWidth() << std::endl;
}


int main(int argc, const char * argv[])
{
    // rectangle inhertis from square
    Square sq = Rectangle();
    calculate(sq); // because a rectangle inhertis from a square, the result will be incorrect.

    // square inhertis from rectangle
    Rectangle2 r = Square2();
    calculate(r); // result will be correct
    
	return 0;
}

