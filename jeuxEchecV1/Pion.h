#pragma once

#include "PionGenerique.h"

class Pion : public PionGenerique
{
public:
	Pion();
	~Pion();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]) override;

	char getPieceSymbol() const override { return 'P'; }

private:
	bool firstMove = true;
};

