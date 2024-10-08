#include "Reine.h"
#include <math.h>

Reine::Reine()
{
}

Reine::~Reine()
{
}

bool Reine::isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8])
{
	// Mouvement vertical
	if (xDep == xArr && yDep != yArr) {
		return true;
	}

	// Mouvement horizontal
	if (xDep != xArr && yDep == yArr) {
		return true;
	}

	// Mouvement diagonal
	if (abs(xArr - xDep) == abs(yArr - yDep)) {
		return true;
	}


    return false;
}
