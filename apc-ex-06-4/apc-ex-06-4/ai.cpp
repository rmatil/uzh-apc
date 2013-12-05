//
//  ai.cpp
//  apc-ex-06-4
//
//  Created by Raphael Matile on 28/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "ai.h"

int ai::play(const my_playfield &pField) {
    my_playfield privateField = pField;
    // either 1 (player1) or 2 (player2)
    playerRole = determinePlayerRole(privateField);
    
    if (playerRole == 2) {
        // determine next move
        return playNext(1, privateField);
    }
    
    // i am player 1 -> i play first
    return playNext(2, privateField);
}

int ai::playNext(int enemyPlayer, my_playfield pField) {
    // check enemy positions
    // if enemy is winning, figure out where to play next stone
    for (int x=0; x<pField.width; x++) {
        my_playfield tmp = pField;
        if (!tmp.isFull(x)) {
            tmp.insertStone(enemyPlayer, x);
            if (tmp.isWinning(enemyPlayer) && !isDiagonalAndLeftEmpty(tmp, x, enemyPlayer) && !isDiagonalAndRightEmpty(tmp, x, enemyPlayer)) {
                return x;
            }
        }
    }
    
    // check own position for the next move
    for (int x=0; x<pField.width; x++) {
        my_playfield tmp = pField; // so no delete method is needed...
        if (!tmp.isFull(x)) {
            tmp.insertStone(playerRole, x);
            if (tmp.isWinning(playerRole)) {
                return x;
            }
        }
    }
    
    // if no direct move to win is found, check a move where i can win in the move after
    for (int x=0; x<pField.width; x++) {
        my_playfield tmp = pField;
        if (!tmp.isFull(x)) {
            tmp.insertStone(playerRole, x);
            // check second move
            // check turn after turn before
            for (int x2=0; x2<pField.width; x2++) {
                my_playfield tmp2 = tmp;
                if (!tmp.isFull(x2)) {
                    tmp.insertStone(playerRole, x2);
                    if (tmp.isWinning(playerRole)) {
                        return x2;
                    }
                }
            }
        }
    }
    
    // no good move found
    // -> random move
    bool isFull = false;
    srand((int)time(NULL)); // initialise random with time as seed
    int column = rand() % 7;
    
    std::cout << "make randomly move..." << std::endl;
    if (pField.isFull(column)) {
        isFull = true;
    }
    
    while (isFull) {
        std::cout << "while..." << std::endl;
        column = rand() % 7;
        if (!pField.isFull(column)) {
            isFull = false;
        }
    }
    
    return column;
}

bool ai::isDiagonalAndLeftEmpty(my_playfield pField, int pColumn, int pPlayer) {
    // pColumn is the third stone in a diagonal way, so that to win, it is
    // required to place a 4th stone in the column left to it
    //
    // example (the other way round)
    //     1
    //   1 2 X <- don't place it
    // 1 2 2 2
    if (pColumn-1 > 0 && pColumn < pField.width) {
        // is in the boundary of the playfield
        pField.insertStone(pPlayer, pColumn-1);
        if (pField.isWinning(pPlayer)) {
            // not an empty place left to pColumn
            return false;
        }
        // is an empty place left to pColumn
        return true;
    }
    return false;
}


bool ai::isDiagonalAndRightEmpty(my_playfield pField, int pColumn, int pPlayer) {
    // pColumn is the third stone in a diagonal way, so that to win, it is
    // required to place a 4th stone in the column left to it
    //
    // example
    //     1
    //   1 2 X <- don't place it
    // 1 2 2 2
    if (pColumn > 0 && pColumn+1 < pField.width) {
        // is in the boundary of the playfield
        pField.insertStone(pPlayer, pColumn+1);
        if (pField.isWinning(pPlayer)) {
            // not an empty place right to pColumn
            return false;
        }
        // is an empty place right to pColumn
        return true;
    }
    return false;
}


// returns 1 for player1, 2 for player2
int ai::determinePlayerRole(my_playfield pField) {
    for (int x=0; x<pField.width; x++) {
        for (int y=0; y<pField.height; y++) {
            if (pField.stoneat(x, y) != pField.none) {
                // playfield is not empty
                // i am player 2
                return 2;
            }
        }
    }
    return 1;
}


