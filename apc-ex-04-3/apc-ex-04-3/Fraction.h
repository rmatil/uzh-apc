//
//  Fraction.h
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __Fraction__Fraction__
#define __Fraction__Fraction__

#include "Util.h"

#include <iostream>


class Fraction {
public:
    Fraction(int pCounter=0, int pDenominator=1);
    
    const int get_counter();
    void set_counter(int cntr);
    const int get_denominator();
    void set_denominator(int pDenominator);
	float to_float();
    
    Fraction operator+(Fraction &pFraction);
    Fraction operator-(Fraction &pFraction);
    Fraction operator*(Fraction &pFraction);
    Fraction operator/(Fraction &pFraction);
	bool operator>(Fraction &pFraction);
	bool operator<(Fraction &pFraction);
	operator float() const;
	
	friend std::ostream &operator<<(std::ostream &pOutput, const Fraction &pFraction);
    friend std::istream &operator>>(std::istream &pInput, Fraction &pFraction);
	
    void reduce();
    void validateFraction(Fraction *pFraction);
    
private:
    int counter;
    int denominator;
    
};


#endif /* defined(__Fraction__Fraction__) */
