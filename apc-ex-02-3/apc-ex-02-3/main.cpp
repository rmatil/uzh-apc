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



using std::cerr;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char * argv[])
{
	
	while (input != "q") {
		cout << "Type in your command:" << endl;
		cin >> input;
		// erase the number on the top of the stack
		if (input == "d") {
			if (stack.size() > 0) {
				stack.erase(stack.begin());
			} else {
				cout << "Your stack is already empty." << endl;
			}
		} else if(input == "n") {
			cout << "Type your number to add to the stack: " << endl;
			float number;
			cin >> number;
			stack.push_back(number);
		} else if (input == "+" || input == "-" || input == "/" || input == "*") {
			if (input == "+") {
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = last + second_last;
				cout << "the result is: " << res << endl;
				stack.push_back(res);
			} else if (input == "-") {
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last - last;
				cout << "the result is: " << res << endl;
				stack.push_back(res);
			} else if (input == "*") {
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last * last;
				cout << "the result is: " << res << endl;
				stack.push_back(res);
			} else if (input == "/") {
				std::vector<float>::iterator it = stack.end();
				--it;
				float last = *it;
				stack.pop_back();
				--it;
				float second_last = *it;
				stack.pop_back();
				float res = second_last / last;
				cout << "the result is: " << res << endl;
				stack.push_back(res);

			} else {
				cout << "Your command is not available. Choose an athoer one." << endl;
				cout << "Available commands are: q, n, d and +,-,*,/." << endl;
			}
		}
		printStack();
	}
    return 0;
}

void printStack() {
	std::vector<float>::iterator pbegin = stack.begin();
	std::vector<float>::iterator pend = stack.end();
	
	for (pbegin; pbegin != pend; ++pbegin) {
		std::cout << "| " << *pbegin << " |" << std::endl;
	}
}

