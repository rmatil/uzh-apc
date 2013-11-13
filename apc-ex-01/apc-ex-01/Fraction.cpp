//
//  Fraction.cpp
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "Fraction.h"

Fraction::Fraction(int pCounter, int pDenominator) {
    counter = pCounter;
	denominator = pDenominator;
	validateFraction(*this);
}

Fraction::Fraction() {
	counter = 0;
	denominator = 1;
}

int Fraction::getCounter() {
    return counter;
}

void Fraction::setCounter(const int cntr) {
    counter = cntr;
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::setDenominator(const int pDenominator) {
    denominator = pDenominator;
    // validating denominator
    try {
    validateFraction(*this);
    } catch (const char *e) {
        std::cerr << e << std::endl;
        std::cerr << "Denominator will be set to 1." << std::endl;
        denominator = 1;
    }
}

Fraction Fraction::operator+(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) + (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
    try {
        tmp.reduce();
    } catch (const char *e) {
        std::cerr << e << std::endl;
    }
    return tmp;
}

Fraction Fraction::operator-(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) - (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
    try {
        tmp.reduce();
    } catch (const char *e) {
        std::cerr << e << std::endl;
    }
    return tmp;
}

Fraction Fraction::operator*(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.counter);
    tmp.denominator = (denominator * pFraction.denominator);
    try {
        tmp.reduce();
    } catch (const char *e) {
        std::cerr << e << std::endl;
    }
    return tmp;
}

Fraction Fraction::operator/(Fraction &pFraction) {
    Fraction tmp;
    // validation of fraction in constructor and in method setDenominator()
    tmp.counter = (counter * pFraction.denominator);
    tmp.denominator = (denominator * pFraction.counter);
    try {
        tmp.reduce();
    } catch (const char *e) {
        std::cerr << e << std::endl;
    }
    return tmp;
}



/*
 * helper methods
 */

// wheter a nor b should be 0
int Fraction::gcf(int a, int b) {
    if (a<b) std::swap(a,b);
    
    while (b!=0) {
        a=a-b;
        if (a<b) std::swap(a,b);
    }
    return a;
}

void Fraction::reduce() {
    int i = counter;
    
    // gcf makes no sense with negative numbers, no effects on gcf
    if(i<0) {
        i *= -1;
    }
    int j = denominator;
    if(j<0) {
        j *= -1;
    }
    
    int result = gcf(i, j);
    
    if (result == 0) {
        throw "Dvide by zero in reduce-method. Reduce not possible";
    }

    // reduce fraction
    counter /= result;
    denominator /= result;
}

void Fraction::validateFraction(Fraction &pFraction) {
    if(pFraction.getDenominator() == 0) {
        throw "Divide by zero in validateFraction-method.";
    }
}


