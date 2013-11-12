//
//  PVector.cpp
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "PSet.h"

template<typename T, typename P>
void PSet<T, P>::read_set() {
	mSet.clear();
	std::ifstream infile(mFilename.c_str());
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << mFilename << " Error: " << strerror(errno) << std::endl;
		exit(1);
	}
    bool isGood = true;
	for (;;) {
		T x;
		persisterTwo::read(infile, x);
		if (!infile.good()) {
			isGood = false;
        }
        if (!isGood) {
            return;
        }
         mSet.insert(x);
	}
}

template<typename T, typename P>
void PSet<T, P>::write_set() {
	std::ofstream outfile(mFilename.c_str(), std::ios::ate | std::ios::app);
	iterator first = mSet.begin();
	iterator last = mSet.end();
	
	while (first != last) {
		persisterTwo::write(outfile, *first++);
	}

}