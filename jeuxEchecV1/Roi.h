#pragma once
#include "PionGenerique.h"
class Roi : public PionGenerique
{
public:
	Roi();
	~Roi();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8]);

	char getPieceSymbol() const override { return 'K'; }

};

