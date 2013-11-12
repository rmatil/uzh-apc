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
#include "Util.h"

class Fraction {
public:
    Fraction(int pCounter=0, int pDenominator=1);
    
    int getCounter();
    void setCounter(int cntr);
    int getDenominator();
    void setDenominator(int pDenominator);
    
    Fraction operator+(Fraction &pFraction);
    Fraction operator-(Fraction &pFraction);
    Fraction operator*(Fraction &pFraction);
    Fraction operator/(Fraction &pFraction);
    
    void reduce();
    void validateFraction(Fraction *pFraction);
    
private:
    int counter;
    int denominator;
    
};


#endif /* defined(__Fraction__Fraction__) */
