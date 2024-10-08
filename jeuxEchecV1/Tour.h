#pragma once
#include "PionGenerique.h"
class Tour : public PionGenerique
{
public:
	Tour();
	~Tour();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8]) override;

	char getPieceSymbol() const override { return 'T'; }

private:
	char color;
};

