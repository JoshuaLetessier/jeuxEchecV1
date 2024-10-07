#pragma once

class PionGenerique
{
public:
	PionGenerique() {};
	virtual ~PionGenerique() {};

	virtual bool isValidMove(int xDep, int yDep, int xArr, int yArr) = 0;

	virtual char getPieceSymbol() const = 0;

	char getColor()  { return color; }
	void setColor(char color)  { this->color = color; }

private:
	char color;
};

