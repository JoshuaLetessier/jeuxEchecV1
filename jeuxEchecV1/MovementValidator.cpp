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
    if (board[xDep][yDep] == nullptr) {
        VERSION_LOG("Il n'y a pas de pi�ce � cet emplacement!");
        return false;
    }

    char pieceColor = board[xDep][yDep]->getColor();

    if (pieceColor != currentPlayer) {
        std::cout << "Ce n'est pas votre pi�ce !" << std::endl;
        return false;
    }

    if (board[xArr][yArr] != nullptr && pieceColor == board[xArr][yArr]->getColor()) {
        VERSION_LOG("Vous ne pouvez pas d�placer votre pi�ce sur une case occup�e par une de vos pi�ces!");
        return false;
    }

    if (xDep == xArr && yDep == yArr) {
        VERSION_LOG("Vous devez d�placer la pi�ce � un autre emplacement!");
        return false;
    }

    if (!board[xDep][yDep]->isValidMove(xDep, yDep, xArr, yArr, board)) {
        VERSION_LOG("D�placement invalide pour cette pi�ce !");
        return false;
    }

    if (!isPathClear(xDep, yDep, xArr, yArr, board)) {
        VERSION_LOG("Le chemin n'est pas d�gag� !");
        return false;
    }

    return true;
}

bool MovementValidator::isPathClear(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
    if (xDep == xArr) {
        return isPathClearVertical(xDep, yDep, xArr, yArr, board);
    }
    else if (yDep == yArr) {
        return isPathClearHorizontal(xDep, yDep, xArr, yArr, board);
    }
    else if (abs(xDep - xArr) == abs(yDep - yArr)) {
        return isPathClearDiagonal(xDep, yDep, xArr, yArr, board);
    }
    return false;
}

bool MovementValidator::isPathClearDiagonal(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8])
{
    int xDirection = (xArr > xDep) ? 1 : -1;
    int yDirection = (yArr > yDep) ? 1 : -1;

    for (int i = 1; i < abs(xArr - xDep); i++) {
        if (board[xDep + i * xDirection][yDep + i * yDirection] != nullptr) {
            VERSION_LOG("Il y a une pi�ce sur le chemin en diagonale!");
            return false;
        }
    }

    return true;
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

