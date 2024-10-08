#pragma once
#include "PionGenerique.h"
class DrawBoard
{
public:
	DrawBoard() {};
	virtual ~DrawBoard() {};

	virtual void drawBoard(PionGenerique* board[8][8]) = 0;

};

