//
//  RPN.cpp
//  apc-ex-03-3
//
//  Created by Raphael Matile on 28.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "RPN.h"


using namespace std;

void RPN::run() {
	while (input_ != "q") {
		cout << "Type in your command:" << endl;
		cin >> input_;
		
		
		// erase the number on the top of the stack
		if (input_ == "d") {
			if (pvector_stack_.size() > 0) {
				pvector_stack_.erase(--pvector_stack_.end());
			} else {
				cout << "Your stack is already empty" << endl;
			}
		} else if(input_ == "n") {
			cout << "Type your number to add to the stack: " << endl;
			float number;
			cin >> number;
			pvector_stack_.push_back(number);
		} else if (input_ == "+" || input_ == "-" || input_ == "/" || input_ == "*") {
            if (pvector_stack_.size() < 2) {
                cout << "Your stack is already empty" << endl;
            } else {
                if (input_ == "+") {
                    std::vector<float>::iterator it = pvector_stack_.end();
                    --it;
                    float last = *it;
                    pvector_stack_.pop_back();
                    --it;
                    float second_last = *it;
                    pvector_stack_.pop_back();
                    float res = last + second_last;
                    cout << "the result is: " << res << endl;
                    pvector_stack_.push_back(res);
                } else if (input_ == "-") {
                    std::vector<float>::iterator it = pvector_stack_.end();
                    --it;
                    float last = *it;
                    pvector_stack_.pop_back();
                    --it;
                    float second_last = *it;
                    pvector_stack_.pop_back();
                    float res = second_last - last;
                    cout << "the result is: " << res << endl;
                    pvector_stack_.push_back(res);
                } else if (input_ == "*") {
                    std::vector<float>::iterator it = pvector_stack_.end();
                    --it;
                    float last = *it;
                    pvector_stack_.pop_back();
                    --it;
                    float second_last = *it;
                    pvector_stack_.pop_back();
                    float res = second_last * last;
                    cout << "the result is: " << res << endl;
                    pvector_stack_.push_back(res);
                } else if (input_ == "/") {
                    std::vector<float>::iterator it = pvector_stack_.end();
                    --it;
                    float last = *it;
                    pvector_stack_.pop_back();
                    --it;
                    float second_last = *it;
                    pvector_stack_.pop_back();
                    float res = second_last / last;
                    cout << "the result is: " << res << endl;
                    pvector_stack_.push_back(res);
                    
                } else {
                    cout << "Your command is not available. Choose another one." << endl;
                }
            }
		}
		
		this->printStack();
	}
	

}


void RPN::printStack() {
	std::vector<float>::reverse_iterator pbegin = pvector_stack_.rbegin();
	std::vector<float>::reverse_iterator pend = pvector_stack_.rend();

	for (; pbegin != pend; ++pbegin) {
		std::cout << "| " << *pbegin << " |" << std::endl;
		
	}
	std::cout << " ---" << std::endl;
}


