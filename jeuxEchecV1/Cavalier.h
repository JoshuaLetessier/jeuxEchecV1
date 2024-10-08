#pragma once
#include "PionGenerique.h"
class Cavalier : public PionGenerique
{
public:
	Cavalier();
	~Cavalier();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8]) override;

	char getPieceSymbol() const override { return 'C'; }
};

