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

const int Fraction::get_counter() {
    return counter;
}

void Fraction::set_counter(int cntr) {
    counter = cntr;
}

const int Fraction::get_denominator() {
    return denominator;
}

void Fraction::set_denominator(int pDenominator) {
    denominator = pDenominator;
    validateFraction(this);
}

float Fraction::to_float() {
	return float(counter)/float(denominator);
}

Fraction Fraction::operator+(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) + (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator-(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.denominator) - (pFraction.counter * denominator);
    tmp.denominator = (denominator * pFraction.denominator);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator*(Fraction &pFraction) {
    Fraction tmp;
    
    // crosswise multiply
    tmp.counter = (counter * pFraction.counter);
    tmp.denominator = (denominator * pFraction.denominator);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator/(Fraction &pFraction) {
    Fraction tmp;
    
    tmp.counter = (counter * pFraction.denominator);
    tmp.denominator = (denominator * pFraction.counter);
    tmp.reduce();
    
    return tmp;
}

Fraction Fraction::operator>(Fraction &pFraction) {
	if (this->to_float()>pFraction.to_float()) {
		return pFraction;
	}
	return *this;
}

Fraction Fraction::operator<(Fraction &pFraction) {
	if (this->to_float()<pFraction.to_float()) {
		return *this;
	}
	return pFraction;
}


Fraction::operator float() const {
	return float(counter)/float(denominator);
}

std::ostream &operator<<(std::ostream &pOutput, const Fraction &pFraction) {
	pOutput << "(" << pFraction.counter << "/" << pFraction.denominator << ")" << " ";
	return pOutput;
}

std::istream &operator>>(std::istream &pInput, Fraction &pFraction) {
	char tmp0, tmp1, tmp2;
    pInput >> tmp0;
	pInput >> pFraction.counter;
	pInput >> tmp1;
	pInput >> pFraction.denominator;
    pInput >> tmp2;
	pFraction.reduce();
	return pInput;
}

/*
 * helper methods
 */

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
    if(pFraction->get_denominator() == 0) {
        throw "Divide by zero is not allowed according to general laws of math.";
    }
}


