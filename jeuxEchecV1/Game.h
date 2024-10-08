#pragma once

#include "Board.h"
#include "DrawBoard.h"
#include "InputHandler.h"
#include "MovementValidator.h"
#include <vector>


class Game
{
public:
	Game();
	~Game();
	void start();

private:
	void initGame();
	void play();
	void endGame();
	void switchPlayer();
	void clearScreen();
	bool modeDemo();

	bool isGame = true;
	bool isGoodMove = false;	
	char currentPlayer = 'B';
	int demoCount = 0;

	Board* board;
	DrawBoard* drawBoard;
	InputHandler* inputHandler;
	MovementValidator* movementValidator;
};

