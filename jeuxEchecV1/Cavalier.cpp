#include "Cavalier.h"
#include <math.h>

Cavalier::Cavalier()
{
}

Cavalier::~Cavalier()
{
}

bool Cavalier::isValidMove(int xDep, int yDep, int xArr, int yArr)
{
	if ((abs(xDep - xArr) == 2 && abs(yDep - yArr) == 1) || (abs(xDep - xArr) == 1 && abs(yDep - yArr) == 2))
	{
		return true;
	}

    return false;
}
