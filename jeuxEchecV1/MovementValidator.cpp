#include "MovementValidator.h"
#include "Define.h"

#include <iostream>


MovementValidator::MovementValidator()
{
}

MovementValidator::~MovementValidator()
{
}

bool MovementValidator::Excute(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8], char currentPlayer)
{
    if (board[xDep][yDep]->getColor() != currentPlayer) {
        std::cout << "Ce n'est pas votre pièce !" << std::endl;
        return false;
    }

    if (board[xDep][yDep] == nullptr) {
        VERSION_LOG("Il n'y a pas de pièce à cet emplacement!");
        return false;;
    }

    if (board[xArr][yArr] != nullptr && board[xDep][yDep]->getColor() == board[xArr][yArr]->getColor()) {
        VERSION_LOG("Vous ne pouvez pas déplacer votre pièce sur une case occupée par une de vos pièces!");
        return false;;
    }

    // Vérifie si la case de départ est la même que la case d'arrivée
    if (xDep == xArr && yDep == yArr) {
        VERSION_LOG("Vous devez déplacer la pièce à un autre emplacement!");
        return false;;
    }

	// Vérifie si le déplacement est valide
    if (!board[xDep][yDep]->isValidMove(xDep, yDep, xArr, yArr)) {
        VERSION_LOG("Déplacement invalide!");
        return false;
    }
    else
    {
        // Déplace la pièce
        std::cout << "Déplacement valide!" << std::endl;
		board[xArr][yArr] = board[xDep][yDep];
		board[xDep][yDep] = nullptr;
        return true;
    }

    return false;
}

bool MovementValidator::isPathClear(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
	if (isPathClearDiagonal(xDep, yDep, xArr, yArr, board) 
        && isPathClearVertical(xDep, yDep, xArr, yArr, board) 
        && isPathClearHorizontal(xDep, yDep, xArr, yArr, board))
	{
		return true;
	}
	return false;
}

bool MovementValidator::isPathClearDiagonal(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
    if (abs(xDep - xArr) == abs(yDep - yArr)) {
        if (xDep < xArr && yDep < yArr) {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep + i][yDep + i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
        else if (xDep < xArr && yDep > yArr) {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep + i][yDep - i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
        else if (xDep > xArr && yDep < yArr) {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep - i][yDep + i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
        else {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep - i][yDep - i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
        }
}

bool MovementValidator::isPathClearVertical(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
    if (xDep == xArr) {
        if (yDep < yArr) {
            for (int i = yDep + 1; i < yArr; i++) {
                if (board[xDep][i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
        else {
            for (int i = yDep - 1; i > yArr; i--) {
                if (board[xDep][i] != nullptr) {
                    VERSION_LOG("Il y a une pièce sur le chemin!");
                    return false;
                }
            }
        }
    }
	return true;
}

bool MovementValidator::isPathClearHorizontal(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
   if (yDep == yArr) {
    if (xDep < xArr) {
        for (int i = xDep + 1; i < xArr; i++) {
            if (board[i][yDep] != nullptr) {
                VERSION_LOG("Il y a une pièce sur le chemin!");
                return false;
            }
        }
    }
    else {
        for (int i = xDep - 1; i > xArr; i--) {
            if (board[i][yDep] != nullptr) {
                VERSION_LOG("Il y a une pièce sur le chemin!");
                return false;
            }
        }
    }
    }
   return true;
}

