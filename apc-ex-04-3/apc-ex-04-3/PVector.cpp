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
    // Note: there must be a new line at the end of stack.txt to work correctly
	mVector.clear();
	std::ifstream infile(mFilename.c_str());
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << mFilename << " Error: " << strerror(errno) << std::endl;
        std::cerr << "Note: If you aren't using Xcode you may have to change the filepaths in 'main.cpp'. Thats because Xcode is using absolute paths to files..." << std::endl;
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

// Note: inline in the specialization method. It is required for the code not to have linker error due to the method being defined more then once.
template<>
inline void PVector<Fraction>::readVector() {
    // Note: there must be a new line at the end of stack.txt to work correctly
	mVector.clear();
	std::ifstream infile(mFilename.c_str());
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << mFilename << " Error: " << strerror(errno) << std::endl;
        std::cerr << "Note: If you aren't using Xcode you may have to change the filepaths in 'main.cpp'. Thats because Xcode is using absolute paths to files..." << std::endl;
        exit(1);
	}
	for (;;) {
		Fraction x;
		infile >> x;
		if (!infile.good()) {
			break;
		}
		mVector.push_back(x);
	}
}


template<typename T>
void PVector<T>::writeVector() {
	std::ofstream outfile(mFilename.c_str(), std::ios::trunc);
	typename std::vector<T>::iterator first = mVector.begin();
	typename std::vector<T>::iterator last = mVector.end();
	std::cout << "------" << std::endl;
	while (first != last) {
		std::cout << "writing to file " << *first << std::endl;
		outfile << *first++ << " ";
	}
}
