//
//  Fraction.cpp
//  Fraction
//
//  Created by Raphael Matile on 19.09.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "Fraction.h"


using namespace std;


Fraction::Fraction(int pCounter, int pDenominator) : counter(pCounter), denominator(pDenominator) {
    validateFraction(this);
}

int Fraction::getCounter() {
    return counter;
}

void Fraction::setCounter(int cntr) {
    counter = cntr;
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::setDenominator(int pDenominator) {
    denominator = pDenominator;
    validateFraction(this);
}

Fraction Fraction::operator+(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) + (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
	validateFraction(&tmp);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator-(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) - (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
	validateFraction(&tmp);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator*(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.counter);
    tmp.denominator = (denominator * pFraction.denominator);
	validateFraction(&tmp);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator/(Fraction &pFraction) {
    Fraction tmp;
    
    tmp.counter = (counter * pFraction.denominator);
    tmp.denominator = (denominator * pFraction.counter);
	validateFraction(&tmp);
    tmp.reduce();
    
    return tmp;
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
    
    int res = gcf(i, j);
    
    // reduce fraction
    counter /= res;
    denominator /= res;
}

void Fraction::validateFraction(Fraction *pFraction) {
    if(pFraction->getDenominator() == 0) {
        throw "Divide par zero.";
    }
}


