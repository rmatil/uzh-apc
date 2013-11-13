//
//  main.cpp
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "PVector.h"
#include "PVector.cpp"  // because of templates


int main(int argc, const char * argv[])
{
    // Test Driver
    // Note: Xcode is using absolute paths to files...
	PVector<int> pvInt = PVector<int>("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-03-2/apc-ex-03-2/pv-int.txt");
	pvInt.push_back(2);
    pvInt.push_back(22222223);
    
    PVector<float> pvFloat = PVector<float>("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-03-2/apc-ex-03-2/pv-float.txt");
	pvFloat.push_back(4.5677);
    pvFloat.push_back(3.1415);
    
    
	PVector<std::string> pvString = PVector<std::string>("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-03-2/apc-ex-03-2/pv-string.txt");
    pvString.push_back("Test1");
    pvString.push_back("Test2");
	
	
	return 0;
}
