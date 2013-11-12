//
//  playfield.cpp
//  apc-ex-04-5
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "playfield.h"

playfield::playfield()
{
	// initalize vec with 0's
	std::vector<int> vec;
	vec.assign(playfield::width, 0);
	rep.assign(playfield::height, vec);
}

playfield::~playfield(){ }

int playfield::stoneat(int pColumn, int pRow) const
{
	return rep[pRow][pColumn];
}

void playfield::drawPlayfield() {
	for (int i=0; i<rep.size(); i++) {
		std::cout << "| ";
		for (int j=0; j<rep.at(i).size(); j++) {
			if (rep.at(i).at(j) == 0) {
				std::cout << "  ";
			} else {
				std::cout << rep.at(i).at(j) << " ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "------------------" << std::endl;
}

void playfield::insertStone(int pPlayer, int pColumn) {
	// check range
	if (pColumn > playfield::width-1) {
		std::cerr << "Column is out of the playfield! Stone could not be inserted." << std::endl;
		exit(EXIT_FAILURE);
	}
	// check wether the desired column is full or not
	if (isFull(pColumn)) {
		std::cerr << "This column is already full. Choose another one:" << std::endl;
		int input;
		std::cin >> input;
		insertStone(pPlayer, input);
	}
	// start on the top of the playfield
	int tmpPlace = 0;
	// go through all rows
	for (int i=0; i<rep.size(); i++) {
		if (rep.at(i).at(pColumn) == 0) {
			// set current row as free place
			tmpPlace = i;
		}
	}
	rep.at(tmpPlace).at(pColumn) = pPlayer;
}

bool playfield::isWinning(int pPlayer) {
	// check horizontal places
	for (int i=0; i<rep.size(); i++) { // height
		for (int j=0; j<rep.at(i).size(); j++) { // width
			// check horizontal places
			if (j < rep.at(i).size()-3) {
				if ((rep.at(i).at(j) == pPlayer)
					&& (rep.at(i).at(j+1) == pPlayer)
					&& (rep.at(i).at(j+2) == pPlayer)
					&& (rep.at(i).at(j+3) == pPlayer)) {
					// found 4 stones of pPlayer
					return true;
				}
			}
			// check vertical places
			if (i < rep.size()-3) {
				if ((rep.at(i).at(j) == pPlayer)
					&& (rep.at(i+1).at(j) == pPlayer)
					&& (rep.at(i+2).at(j) == pPlayer)
					&& (rep.at(i+3).at(j) == pPlayer)) {
					// found 4 stones of pPlayer
					return true;
				}
			}
			// check diagonal way, starting in top left and go to bottom rights
			if ((i < rep.size()-3) && (j < rep.at(i).size()-3)) {
				if ((rep.at(i).at(j) == pPlayer)
					&& (rep.at(i+1).at(j+1) == pPlayer)
					&& (rep.at(i+2).at(j+2) == pPlayer)
					&& (rep.at(i+3).at(j+3) == pPlayer)) {
					// found 4 stones of pPlayer
					return true;
				}
			}
			// check diagonal way, starting in top right and go to bottom left
			if ((i < rep.size()-3) && (j < rep.at(i).size()-3)) {
				if ((rep.at(i+3).at(j) == pPlayer)
					&& (rep.at(i+2).at(j+1) == pPlayer)
					&& (rep.at(i+1).at(j+2) == pPlayer)
					&& (rep.at(i).at(j+3) == pPlayer)) {
					// found 4 stones of pPlayer
					return true;
				}
			}

		}
	}
	// not winning
	return false;
}

void playfield::clearPlayfield() {
	for (int i=0; i<rep.size(); i++) {
		for (int j=0; j<rep.size(); j++) {
			rep.at(i).at(j) = 0;
		}
	}
}

bool playfield::isFull() {
	bool isFull = true;
	// going through the whole playfield
	for (int i=0; i<rep.size(); i++) {
		for (int j=0; j<rep.at(i).size(); j++) {
			if (!isFull) {
				return isFull;
			}
			if (rep.at(i).at(j) != 0) {
				isFull = true;
			} else {
				isFull = false;
			}
		}
	}
	return isFull;
}

bool playfield::isFull(int pColumn) {
	bool isFull = true;
	// going through the whole column
	for (int i=0; i<rep.size(); i++) {
		if (!isFull) {
			return isFull;
		}
		if (rep.at(i).at(pColumn) != 0) {
			isFull = true;
		} else {
			isFull = false;
		}
	}
	return isFull;
}