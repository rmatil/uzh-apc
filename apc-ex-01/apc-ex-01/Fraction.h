//
//  Fraction.h
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __Fraction__Fraction__
#define __Fraction__Fraction__

#include <iostream>

class Fraction {
public:
    Fraction(int pCounter, int pDenominator);
	Fraction();
    int getCounter();
    void setCounter(const int cntr);
    int getDenominator();
    void setDenominator(const int pDenominator);
    
    Fraction operator+(Fraction &pFraction);
    Fraction operator-(Fraction &pFraction);
    Fraction operator*(Fraction &pFraction);
    Fraction operator/(Fraction &pFraction);
    
    void reduce();
    int gcf(int a, int b); //ggT
    void validateFraction(Fraction &pFraction);
    
private:
    int counter;
    int denominator;
    
};


#endif /* defined(__Fraction__Fraction__) */
