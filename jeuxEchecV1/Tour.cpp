#include "Tour.h"

Tour::Tour()
{
}

Tour::~Tour()
{
}

bool Tour::isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8])
{
	// Vérifie si le déplacement est valide pour une tour
	int direction = (getColor() == 'B') ? 1 : -1;

	// Mouvement vertical
	if (xDep == xArr && yDep != yArr)
	{
		return true;
	}

	// Mouvement horizontal
	if (xDep != xArr && yDep == yArr)
	{
		return true;
	}

    return false;
}
