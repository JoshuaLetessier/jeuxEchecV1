#pragma once
#include "PionGenerique.h"
class Reine : public PionGenerique
{
public:
	Reine();
	~Reine();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8]) override;

	char getPieceSymbol() const override { return 'Q'; }
};

