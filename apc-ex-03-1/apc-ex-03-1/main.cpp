//
//  main.cpp
//  apc-ex-03-1
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>

class A
{
public:
    virtual int foo() { return 1; }
};

class B : public A
{
public:
    virtual int foo() { return 2; }
};


/*
 Virtual means, that the behaviour can be overwritten in a child class.
 The main function will return 2 and not 1.
 If the compiler inline the function it will return 1 because the compiler 
 can only assume that the type of *a is A and not B.
 So the compiler will not do it if he cannot assume safely the type of *a.
 In this example the compiler may successfully and safely assume that 
 virtualization is not needed : This is really depending of the compiler and of optimization level.
 In some case the compiler can safely assume that virtualization is not needed and 
 only in these cases the inline keyword makes sense.
 Even if you declare a function with the keywords inline, the function may not be inlined.
 Anyway adding manually the inline keyword is most of the time not a good idea, 
 compiler today are good and automatically inline function when necessary. 
 By adding inline you may in some case decrease performance, so it a good practice to not abuse of it
 
 Stackoverflow (23.10.13): http://stackoverflow.com/questions/14122637/why-that-pure-virtual-function-cannot-be-inline
 
*/


int main(void)
{
    B b;
    A *a = &b;
	
	std::cout <<  a->foo() << std::endl;
	return 0;
}
