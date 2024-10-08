#include "Pion.h"

Pion::Pion()
{
}

Pion::~Pion()
{
}

bool Pion::isValidMove(int xDep, int yDep, int xArr, int yArr)
{
	// Vérifie si le déplacement est valide pour un pion
    int direction = (getColor() == 'B') ? 1 : -1;

    // Mouvement vers l'avant d'une case
    if (xArr == xDep + direction && yArr == yDep) {
		if (firstMove) firstMove = false;
        return true;
    }

	// Mouvement en diagonale pour manger une pièce
    if (xArr == xDep + direction && (yArr == yDep + 1 || yArr == yDep - 1) ){
		return true;
    }

	// Premier mouvement de deux cases
	if (firstMove && xArr == xDep + 2 * direction && yArr == yDep) {
		firstMove = false;
		return true;
	}
	return false;
}