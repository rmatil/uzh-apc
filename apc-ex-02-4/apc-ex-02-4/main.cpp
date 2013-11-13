//
//  main.cpp
//  apc-ex-02-4
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <cerrno>

std::set<std::string> dictionary;
void readDictionary(const char *pPath);
void check(const char *pPath);

int main(int argc, const char * argv[])
{
	if (argc < 3) {
		std::cerr << "Too few arguments to start program." << std::endl;
		std::cerr << "Usage: dictionary.txt text.txt" << std::endl;
		exit(1);
	}
	// read dictonary from file
	readDictionary(argv[1]);
	check(argv[2]);
    
	
	return 0;
}

// read Patterns
void readDictionary(const char *pPath) {
	std::ifstream infile;
	infile.open(pPath);
	
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << pPath << ", Error: " << strerror(errno) << std::endl;
		infile.close();
		exit(2);
	}
	
	while (!infile.eof()) {
		std::string tmp;
        std::string result;
		infile >> tmp;
        // remove puncuation
        std::remove_copy_if( tmp.begin(),
                            tmp.end(),
                            std::back_inserter(result),
                            std::ptr_fun<int, int>(&std::ispunct));
		dictionary.insert(result);
	}
	
	infile.close();
}


// check if word is stored in the set
void check(const char *pPath) {
	std::ifstream infile;
	infile.open(pPath);
	
	if (!infile.good()) {
		std::cerr << "An error occured during file read. File: " << pPath << ", Error: " << strerror(errno) << std::endl;
		infile.close();
		exit(2);
	}
	
	while (!infile.eof()) {
		std::string tmp;
        std::string result;
		infile >> tmp;
        // remove punctuation
        std::remove_copy_if( tmp.begin(),
                            tmp.end(),
                            std::back_inserter(result),
                            std::ptr_fun<int, int>(&std::ispunct));
		if (dictionary.find(result) == dictionary.end()) {
			 // word not found
			std::cout << tmp << std::endl;
		}
	}
	std::cout << "All words checked." << std::endl;
}
