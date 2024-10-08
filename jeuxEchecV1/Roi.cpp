#include "Roi.h"

Roi::Roi()
{}

Roi::~Roi()
{}

bool Roi::isValidMove(int xDep, int yDep, int xArr, int yArr, PionGenerique* /*unused*/[8][8])
{
	// Vérifie si le déplacement est valide pour un roi
	int direction = (getColor() == 'B') ? 1 : -1;

	// Mouvement vertical
	if ((xArr == xDep + direction || xArr == xDep - direction) && yArr == yDep) {
		return true;
	}

	// Mouvement horizontal
	if (xArr == xDep && (yArr == yDep + 1 || yArr == yDep - 1)) {
		return true;
	}

	// Mouvement diagonal
	if ((xArr == xDep + direction && yArr == yDep + 1) ||
		(xArr == xDep - direction && yArr == yDep - 1) ||
		(xArr == xDep - direction && yArr == yDep + 1) ||
		(xArr == xDep + direction && yArr == yDep - 1))
	{
		return true;
	}
    return false;
}
