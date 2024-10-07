#include "Fou.h"
#include <math.h>

Fou::Fou()
{
}

Fou::~Fou()
{
}

bool Fou::isValidMove(int xDep, int yDep, int xArr, int yArr)
{
	//Mouvement diagonal
	if (abs(xDep - xArr) == abs(yDep - yArr))
	{
		return true;
	}

    return false;
}
