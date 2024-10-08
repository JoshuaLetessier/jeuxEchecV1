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
        std::cout << "Ce n'est pas votre pi�ce !" << std::endl;
        return false;
    }

    if (board[xDep][yDep] == nullptr) {
        VERSION_LOG("Il n'y a pas de pi�ce � cet emplacement!");
        return false;;
    }

    if (board[xArr][yArr] != nullptr && board[xDep][yDep]->getColor() == board[xArr][yArr]->getColor()) {
        VERSION_LOG("Vous ne pouvez pas d�placer votre pi�ce sur une case occup�e par une de vos pi�ces!");
        return false;;
    }

    // V�rifie si la case de d�part est la m�me que la case d'arriv�e
    if (xDep == xArr && yDep == yArr) {
        VERSION_LOG("Vous devez d�placer la pi�ce � un autre emplacement!");
        return false;;
    }

	// V�rifie si le d�placement est valide
    if (!board[xDep][yDep]->isValidMove(xDep, yDep, xArr, yArr)) {
        VERSION_LOG("D�placement invalide!");
        return false;
    }
    else
    {
        // D�place la pi�ce
        std::cout << "D�placement valide!" << std::endl;
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
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
                    return false;
                }
            }
        }
        else if (xDep < xArr && yDep > yArr) {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep + i][yDep - i] != nullptr) {
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
                    return false;
                }
            }
        }
        else if (xDep > xArr && yDep < yArr) {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep - i][yDep + i] != nullptr) {
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
                    return false;
                }
            }
        }
        else {
            for (int i = 1; i < abs(xDep - xArr); i++) {
                if (board[xDep - i][yDep - i] != nullptr) {
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
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
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
                    return false;
                }
            }
        }
        else {
            for (int i = yDep - 1; i > yArr; i--) {
                if (board[xDep][i] != nullptr) {
                    VERSION_LOG("Il y a une pi�ce sur le chemin!");
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
                VERSION_LOG("Il y a une pi�ce sur le chemin!");
                return false;
            }
        }
    }
    else {
        for (int i = xDep - 1; i > xArr; i--) {
            if (board[i][yDep] != nullptr) {
                VERSION_LOG("Il y a une pi�ce sur le chemin!");
                return false;
            }
        }
    }
    }
   return true;
}

