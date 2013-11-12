//
//  PSet.h
//  apc-ex-03-2
//
//  Created by Raphael Matile on 23.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_03_2__PSet__
#define __apc_ex_03_2__PSet__

#include <iostream>
#include <set>
#include <fstream>
#include <cerrno>

template<typename T>
struct persisterTwo {
	static void	read(std::ifstream &i, T &elem) {
		i >> elem;
	}
	static void	write(std::ofstream &o, const T &elem) {
		o << elem << " ";
	}
};

template<>
struct persisterTwo<std::string> {
	static void	read(std::ifstream &i, std::string &elem) {
        std::getline(i, elem);
	}
	static void	write(std::ofstream &o, const std::string &elem) {
		if (elem != "") {
            o << elem << "\n";
        }
	}
};

template<typename T, typename P=persisterTwo<T> >
class PSet {
	typedef P persisterTwo;
	typedef typename std::set<T>::iterator iterator;
	
private:
	std::string mFilename;
	std::set<T> mSet;
	
	void read_set();
	void write_set();
	
public:
	PSet() {
		mFilename = "";
	}
	PSet(std::string pName) : mFilename(pName) {
		read_set();
	}
	~PSet() {
		write_set();
	}
	unsigned long size() {
		return mSet.size();
	}
	T at(const int pPos) {
		return mSet.at(pPos);
	}
	void insert(typename std::set<T>::iterator &pPosition, const T &elem) {
		mSet.insert(pPosition, elem);
	}
	void insert(const T &elem) {
        mSet.insert(elem);
    }
	void erase(typename std::set<T>::iterator pPosition) {
		mSet.erase(pPosition);
	}
	typename std::set<T>::iterator begin() {
		return mSet.begin();
	}
	typename std::set<T>::iterator end() {
		return mSet.end();
	}
	typename std::set<T>::reverse_iterator rbegin() {
		return mSet.rbegin();
	}
	typename std::set<T>::reverse_iterator rend() {
		return mSet.rend();
	}
};



#endif /* defined(__apc_ex_03_2__PSet__) */
