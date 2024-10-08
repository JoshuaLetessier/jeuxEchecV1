#pragma once
#include "PionGenerique.h"
class Fou :
    public PionGenerique
{
public:
	Fou();
	~Fou();
	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]) override;

	char getPieceSymbol() const override { return 'F'; }
};

