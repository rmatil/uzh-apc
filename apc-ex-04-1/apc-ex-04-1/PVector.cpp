//
//  PVector.cpp
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "PVector.h"

template<typename T, typename P>
void PVector<T, P>::readVector() {
	mVector.clear();
	std::ifstream infile(mFilename.c_str());
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << mFilename << " Error: " << strerror(errno) << std::endl;
		exit(1);
	}
	for (;;) {
		T x;
		persister::read(infile, x);
		if (!infile.good()) {
			break;
		}
		mVector.push_back(x);
	}
}

template<typename T, typename P>
void PVector<T, P>::writeVector() {
	std::ofstream outfile(mFilename.c_str(), std::ios::ate | std::ios::app);
	iterator first = mVector.begin();
	iterator last = mVector.end();
	
	while (first != last) {
		persister::write(outfile, *first++);
	}
}
