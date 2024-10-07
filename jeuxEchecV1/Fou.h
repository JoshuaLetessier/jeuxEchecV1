#pragma once
#include "PionGenerique.h"
class Fou :
    public PionGenerique
{
public:
	Fou();
	~Fou();
	bool isValidMove(int xDep, int yDep, int xArr, int yArr) override;

	char getPieceSymbol() const override { return 'F'; }
};

