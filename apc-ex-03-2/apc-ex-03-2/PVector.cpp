//
//  PVector.cpp
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "PVector.h"

template<typename T>
void PVector<T>::readVector() {
	mVector.clear();
	std::ifstream infile(mFilename.c_str());
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << mFilename << " Error: " << strerror(errno) << std::endl;
		exit(1);
	}
	for (;;) {
		T x;
		infile >> x;
		if (!infile.good()) {
			break;
		}
		mVector.push_back(x);
	}
}

template<typename T>
void PVector<T>::writeVector() {
	std::ofstream outfile(mFilename.c_str(), std::ios::ate | std::ios::app);
	typename std::vector<T>::iterator first = mVector.begin();
	typename std::vector<T>::iterator last = mVector.end();
	std::cout << "------" << std::endl;
	while (first != last) {
		std::cout << "writing to file " << *first << std::endl;
		outfile << *first++ << " ";
	}
}
