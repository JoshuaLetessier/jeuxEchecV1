#pragma once
#include "PionGenerique.h"
class Cavalier : public PionGenerique
{
public:
	Cavalier();
	~Cavalier();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr) override;

	char getPieceSymbol() const override { return 'C'; }
};

