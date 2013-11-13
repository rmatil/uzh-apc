//
//  PVector.h
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_03_2__PVector__
#define __apc_ex_03_2__PVector__

#include <iostream>
#include <vector>
#include <fstream>
#include <cerrno>
#include "Fraction.h"


template<class T> class PVector {
private:
	std::string mFilename;
	std::vector<T> mVector;
	
	void readVector();
	void writeVector();
	
public:
	PVector() {
		mFilename = "";
	}
	PVector(std::string pName) : mFilename(pName) {
		readVector();
	}
	~PVector() {
		writeVector();
	}
    void setFilename(std::string pFilename) {
        mFilename = pFilename;
        readVector();
    }
	void push_back(const T &pElement) {
		mVector.push_back(pElement);
	}
	void pop_back() {
		mVector.pop_back();	
	}
	unsigned long size() {
		return mVector.size();
	}
	T at(const int pPos) {
		return mVector.at(pPos);
	}
	void erase(typename std::vector<T>::iterator pPosition) {
		mVector.erase(pPosition);
	}
	typename std::vector<T>::iterator begin() {
		return mVector.begin();
	}
	typename std::vector<T>::iterator end() {
		return mVector.end();
	}
	typename std::vector<T>::reverse_iterator rbegin() {
		return mVector.rbegin();
	}
	typename std::vector<T>::reverse_iterator rend() {
		return mVector.rend();
	}
    bool empty() {
        return mVector.empty();
    }


	
	
};



#endif /* defined(__apc_ex_03_2__PVector__) */
