#pragma once
#include "DrawBoard.h"

class ConsoleDrawBoard : public DrawBoard
{
public:
	ConsoleDrawBoard();
	virtual ~ConsoleDrawBoard();

	void drawBoard(PionGenerique* board[8][8]) override;
};

