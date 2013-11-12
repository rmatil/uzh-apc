//
//  main.cpp
//  apc-ex-04-1
//
//  Created by Raphael Matile on 30.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "PVector.h"
#include "PVector.cpp"
#include "PSet.h"
#include "PSet.cpp"

// Since Xcode is using absolute paths to textfiles, there are different constructors for PVector/PSet
void makefileFileOps() {
    // Vectors
    PVector<int, persister<int> > pvInt = PVector<int, persister<int> >("tmp.txt");
    pvInt.push_back(12);
    pvInt.push_back(13);
    
    PVector<std::string, persister<std::string> > pv = PVector<std::string, persister<std::string> >("tmp2.txt");
    pv.push_back("Test1.");
    pv.push_back("Test2.a Test2.b Test2.c");
    
    // Sets: unique Values
	PSet<int, persisterTwo<int> > psInt = PSet<int, persisterTwo<int> >("tmp3.txt");
    psInt.insert(2);
    psInt.insert(4);
    
    PSet<std::string, persisterTwo<std::string> > ps = PSet<std::string, persisterTwo<std::string> >("tmp4.txt");
    std::string a = "Test1";
    std::string b = "Test2.a Test2.b Test2.c";
	ps.insert(a);
	ps.insert(b);
}


// Since Xcode is using absolute paths to textfiles, there are different constructors for PVector/PSet
void defaultFileOps() {
    // Vectors
    PVector<int, persister<int> > pvInt = PVector<int, persister<int> >("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-1/apc-ex-04-1/tmp.txt");
    pvInt.push_back(12);
    pvInt.push_back(13);
    
    PVector<std::string, persister<std::string> > pv = PVector<std::string, persister<std::string> >("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-1/apc-ex-04-1/tmp2.txt");
    pv.push_back("Test1.");
    pv.push_back("Test2.a Test2.b Test2.c");
    
    // Sets: unique Values
	PSet<int, persisterTwo<int> > psInt = PSet<int, persisterTwo<int> >("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-1/apc-ex-04-1/tmp3.txt");
    psInt.insert(2);
    psInt.insert(4);
    
    PSet<std::string, persisterTwo<std::string> > ps = PSet<std::string, persisterTwo<std::string> >("/Users/Raphael/Dropbox/uzh/uzh-13-fall/uzh-apc/uzh-apc-ex/apc-ex-04-1/apc-ex-04-1/tmp4.txt");
    std::string a = "Test1";
    std::string b = "Test2.a Test2.b Test2.c";
	ps.insert(a);
	ps.insert(b);
   
}

int main(int argc, const char * argv[])
{
    // use makefileFileOps for compilation with makefile
    defaultFileOps();
    
	return 0;
}

