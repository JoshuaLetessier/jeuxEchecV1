#pragma once
#include "PionGenerique.h"
class Reine : public PionGenerique
{
public:
	Reine();
	~Reine();

	bool isValidMove(int xDep, int yDep, int xArr, int yArr) override;

	char getPieceSymbol() const override { return 'Q'; }
};

