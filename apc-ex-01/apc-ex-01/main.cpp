//
//  main.cpp
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "Fraction.h"


int main(int argc, const char * argv[]) {
	Fraction f1(2,6);
    Fraction f2(1,2);
	
    // provocate an exception by setting denominator=0
    try {
        Fraction f7(1,0);
	} catch (const char *pException) {
		std::cerr << pException << std::endl;
	}
    
    // create results
    // catch possible "divides by zero"
    Fraction f3, f4, f5, f6;

    try {
        f3 = f1*f2;
        f4 = f1/f2;
        f5 = f1+f2;
        f6 = f1-f2;
    } catch (const char *pException) {
		std::cerr << pException << std::endl;
	}
    
    std::cout << "original fractions: " << f1.getCounter() << ":" << f1.getDenominator() << " and " << f2.getCounter() << ":" << f2.getDenominator() << std::endl;
   
  
    std::cout << "*: " << f3.getCounter() << ":" << f3.getDenominator() << std::endl;
    std::cout << "/: " << f4.getCounter() << ":" << f4.getDenominator() << std::endl;
    std::cout << "+: " << f5.getCounter() << ":" << f5.getDenominator() << std::endl;
    std::cout << "-: " << f6.getCounter() << ":" << f6.getDenominator() << std::endl;
    
    return 0;
}

