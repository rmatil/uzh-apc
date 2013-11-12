//
//  main.cpp
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, const char * argv[]) {
	Fraction f1(2,6);
    Fraction f2(1,2);
	try {
	Fraction f7(1,0);
	} catch (const char *pException) {
		std::cerr << pException << std::endl;
	}
    
    Fraction f3, f4, f5, f6;
    
    f3 = f1*f2;
    f4 = f1/f2;
    f5 = f1+f2;
    f6 = f1-f2;
    
    cout << "original fractions: " << f1.getCounter() << ":" << f1.getDenominator() << " and " << f2.getCounter() << ":" << f2.getDenominator() << endl;
    try {
	cout << "*: " << f3.getCounter() << ":" << f3.getDenominator() << endl;
    cout << "/: " << f4.getCounter() << ":" << f4.getDenominator() << endl;
    cout << "+: " << f5.getCounter() << ":" << f5.getDenominator() << endl;
    cout << "-: " << f6.getCounter() << ":" << f6.getDenominator() << endl;
    } catch (const char *pException) {
		std::cerr << pException << std::endl;
	}
    return 0;
}

