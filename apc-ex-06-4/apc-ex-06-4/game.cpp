//
//  game.cpp
//  apc-ex-06-04
//
//  Created by Raphael Matile on 07.11.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include "game.h"



template<typename P1, typename P2>
game<P1, P2>::game(P1 &pPlayer1, P2 &pPlayer2) {
	player1 = pPlayer1;
	player2 = pPlayer2;
	isRunning = true;
}

// starts the gameloop
template<typename P1, typename P2>
void game<P1, P2>::run(my_playfield &pField) {
	std::cout << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "        STARTING GAME" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << std::endl;
	pField.drawPlayfield();

	while (isRunning) {
		if (isRunning) {
			// Player 1
			std::cout << "Player1's turn:" << std::endl;
			int column = player1.play(pField);
			pField.insertStone(playfield::player1, column);
			
			// checks
			if(pField.isWinning(playfield::player1)) {
				std::cout << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "        PLAYER 1 WINS" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << std::endl;
				isRunning = false;
			}
			if (pField.isFull()) {
				std::cout << "Playfield is full. Game ends." << std::endl;
				isRunning = false;
			}
			pField.drawPlayfield();
		}
		
		if (isRunning) {
			// Player 2
			std::cout << "Player2's turn:" << std::endl;
			int column = player2.play(pField);
			pField.insertStone(playfield::player2, column);
			
			// checks
			if (pField.isWinning(playfield::player2)) {
				std::cout << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "        PLAYER 2 WINS" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << "******************************" << std::endl;
				std::cout << std::endl;
				isRunning = false;
			}
			if (pField.isFull()) {
				std::cout << "Playfield is full. Game ends." << std::endl;
				isRunning = false;
			}
			pField.drawPlayfield();

		}
	}
	
	std::cout << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "        GAME ENDED" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << std::endl;
}
