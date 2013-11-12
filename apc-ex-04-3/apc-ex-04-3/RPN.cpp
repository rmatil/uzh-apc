//
//  RPN.cpp
//  apc-ex-03-3
//
//  Created by Raphael Matile on 28.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "RPN.h"


using namespace std;

template<typename T>
void RPN<T>::run() {
	while (input_ != "q") {
		cout << "Type in your command:" << endl;
		cin >> input_;
		
		try {
			// erase the number on the top of the stack
			if (input_ == "d") {
				remove();
			} else if(input_ == "n") {
				add();
			} else if (input_ == "m") {
				compute_min();
			} else if (input_ == "+" || input_ == "-" || input_ == "/" || input_ == "*") {
				if (input_ == "+") {
					addition();
				} else if (input_ == "-") {
					subtraction();
				} else if (input_ == "*") {
					mulitplication();
				} else if (input_ == "/") {
					division();
				}
			} else {
				if (input_ != "q") {
					cout << "Your command is not available. Choose another one." << endl;
				}
			}
			this->printStack();
		} catch (const char *&pException) {
			cout << pException << endl;
		}
	}
}

template<typename T>
void RPN<T>::add() {
	cout << "Type your number to add to the stack: " << endl;
	T number;
	cin >> number;
	stack_.push_back(number);
	end_ = --stack_.end();
}

template<typename T>
void RPN<T>::remove() {
	if (stack_.size() > 0) {
		stack_.pop_back();
		end_ = stack_.end();
	} else {
		throw "Note: Your stack is already empty.";
	}
}

template<typename T>
void RPN<T>::compute_min() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	end_ = stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	my_min_val = first_;
    // std::bind(): The function template bind generates a forwarding call wrapper for f. Calling this wrapper is equivalent to invoking f with some of its arguments bound to args.
	for_each(--stack_.begin(), ++stack_.end(), std::bind(&RPN<T>::mymin,this,std::placeholders::_1));
	stack_.push_back(my_min_val);
	++end_;
}

template<typename T>
void RPN<T>::mymin(const T &a) {
	if (a < my_min_val) {
		my_min_val = a;
	}
}

template<typename T>
void RPN<T>::addition() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	end_= stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	T res = first_ + second_;
	printRes(res);
	stack_.push_back(res);
	++end_;

}

template<typename T>
void RPN<T>::subtraction() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	end_= stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	T res = first_ - second_;
	printRes(res);
	stack_.push_back(res);
	++end_;
}

template<typename T>
void RPN<T>::mulitplication() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	end_= stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	T res = first_ + second_;
	printRes(res);
	stack_.push_back(res);
	++end_;
}

template<typename T>
void RPN<T>::division() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	if ((float)*end_ == 0.0f) {
		throw "Error: Division by zero is not allowed...";
	}
	
	end_= stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	T res = first_ / second_;
	cout << "the result is: " << res << endl;
	stack_.push_back(res);
	
}

template<typename T>
void RPN<T>::arctan() {
	if (isEmpty()) {
		throw "Error: Stack is empty.";
	}
	if (tooShort()) {
		throw "Error: Stack has only one element.";
	}
	end_= stack_.end();
	--end_;
	first_ = *end_;
	stack_.pop_back();
	--end_;
	second_ = *end_;
	stack_.pop_back();
	T res = first_ + second_;
	printRes(res);
	stack_.push_back(res);
	++end_;
}

template<typename T>
void RPN<T>::printRes(const T pRes) {
	cout << "the result is: " << pRes << endl;
}

template<typename T>
void RPN<T>::printStack() {
	typename std::vector<T>::reverse_iterator pbegin = stack_.rbegin();
	typename std::vector<T>::reverse_iterator pend = stack_.rend();
	
	if (pbegin == pend) {
		// empty stack
		std::cout << "|   |" << std::endl;
		std::cout << " ---" << std::endl;
		return;
	}
	unsigned long width = 0;
	for (;pbegin != pend; ++pbegin) {
		unsigned long tmp = std::to_string(*pbegin).length();
		if (tmp > width) {
			width = tmp;
		}
		std::cout << "| " << *pbegin << " |" << std::endl;
	}
	std::cout << " ";
	for (unsigned long i=0; i<width-1; i++) {
		std::cout << "-";
	}
	std::cout << " " << std::endl;
}


