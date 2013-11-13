//
//  main.cpp
//  apc-ex-02-3
//
//  Created by Raphael Matile on 12.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>     /* atoi */

void printUsage();
void operate(const char* pOperation);
void printStack();

std::vector<float> stack;
std::string input;


int main(int argc, const char * argv[])
{
	// rpn loop
	while (input != "q") {
		std::cout << "Type in your command:" << std::endl;
		std::cin >> input;
        
		if (input == "d") {
            // erase number on the top of the stack
			if (stack.size() > 0) {
				stack.erase(stack.begin());
			} else {
				std::cout << "Your stack is already empty." << std::endl;
			}
		} else if(input == "n") {
            // adding new number to stack
			std::cout << "Type your number to add to the stack: " << std::endl;
			float number;
            
			// check input
            if (std::cin >> number) {
                stack.push_back(number);
            } else {
                std::cerr << "Type in a valid number next time." << std::endl;
                std::cin.clear();
                exit(EXIT_FAILURE); // shortcoming...
            }
		} else if (((input == "+") || (input == "-") || (input == "/") || (input == "*")) && (stack.size() > 1)) {
			if (input == "+") {
                // addition
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = last + second_last;
				std::cout << "the result is: " << res << std::endl;
				stack.push_back(res);
			} else if (input == "-") {
                // subtraction
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last - last;
				std::cout << "the result is: " << res << std::endl;
				stack.push_back(res);
			} else if (input == "*") {
                // multipliaction
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last * last;
				std::cout << "the result is: " << res << std::endl;
				stack.push_back(res);
			} else if (input == "/") {
                // division
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last / last;
				std::cout << "the result is: " << res << std::endl;
				stack.push_back(res);
			} else {
                // command not specified
				std::cout << "Your command is not available. Choose an athoer one." << std::endl;
				std::cout << "Available commands are: +,-,*,/." << std::endl;
			}
        } else if (input != "+" || input != "-" || input != "*" || input != "/") {
            // command not specified
            if (input != "q") {
                std::cout << "Your command is not available. Choose an athoer one." << std::endl;
                std::cout << "Available commands are: q, n, d." << std::endl;
            }
		} else {
             std::cerr << "Stack has only one element. Could not operate." << std::endl;
        }
		printStack();
	}
    return 0;
}

void printStack() {
	std::vector<float>::iterator pbegin = stack.begin();
	std::vector<float>::iterator pend = stack.end();
	// shortcoming: view of numbers with different number of digits is a bit messy...
	for (; pbegin != pend; ++pbegin) {
		std::cout << "| " << *pbegin << " |" << std::endl;
	}
}

