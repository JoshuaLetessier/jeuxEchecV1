#include "Board.h"
#include <iostream>
#include <string>
#include "Pion.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Reine.h"
#include "Roi.h"


#include "Define.h"


Board::Board()
{
}

Board::~Board()
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x] != nullptr) {
				delete board[y][x];  // Libère toutes les pièces restantes
			}
		}
	}
}

void Board::initBoard()
{
	std::cout << "oh" << std::endl;
#ifdef VERSION_LIGHT
	std::cout << "Version li" << std::endl;
	// Initialisation des pions blancs
	for (int i = 0; i < 8; i++) {
		Pion* pion = new Pion();
		board[1][i] = pion;
		board[1][i]->setColor('B');
	}
	// Initialisation des pions noirs
	for (int i = 0; i < 8; i++) {
		Pion* pion = new Pion();
		board[6][i] = pion;  // Correctement placé en rangée 6 pour les pions noirs
		board[6][i]->setColor('N');
	}

	// Initialisation des tours blancs
	for (int i = 0; i < 8; i++) {
		Tour* tour = new Tour();
		board[0][i] = tour;
		board[0][i]->setColor('B');
	}
	// Initialisation des tours noirs
	for (int i = 0; i < 8; i++) {
		Tour* tour = new Tour();
		board[7][i] = tour;  // Correctement placé en rangée 6 pour les pions noirs
		board[7][i]->setColor('N');
	}

	for (int y = 2; y < 6; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = nullptr;
		}
	}



#else 
	// Initialisation des pions blancs
	for (int i = 0; i < 8; i++) {
		Pion* pion = new Pion();
		board[1][i] = pion;
		board[1][i]->setColor('B');
	}

	// Initialisation des pions noirs
	for (int i = 0; i < 8; i++) {
		Pion* pion = new Pion();
		board[6][i] = pion;  // Correctement placé en rangée 6 pour les pions noirs
		board[6][i]->setColor('N');
	}

	// Initialisation des tours blanches
	Tour* tourB1 = new Tour();
	board[0][0] = tourB1;
	board[0][0]->setColor('B');

	Tour* tourB2 = new Tour();
	board[0][7] = tourB2;  // Position correcte pour la deuxième tour
	board[0][7]->setColor('B');

	// Initialisation des tours noires
	Tour* tourN1 = new Tour();
	board[7][0] = tourN1;  // Position correcte pour la première tour noire
	board[7][0]->setColor('N');

	Tour* tourN2 = new Tour();
	board[7][7] = tourN2;  // Position correcte pour la deuxième tour noire
	board[7][7]->setColor('N');

	// Initialisation des cavaliers 'B's
	Cavalier* cavalierB1 = new Cavalier();
	board[0][1] = cavalierB1;
	board[0][1]->setColor('B');

	Cavalier* cavalierB2 = new Cavalier();
	board[0][6] = cavalierB2;  // Position correcte pour le deuxième cavalier 'B'
	board[0][6]->setColor('B');

	// Initialisation des cavaliers noirs
	Cavalier* cavalierN1 = new Cavalier();
	board[7][1] = cavalierN1;  // Position correcte pour le premier cavalier noir
	board[7][1]->setColor('N');

	Cavalier* cavalierN2 = new Cavalier();
	board[7][6] = cavalierN2;  // Position correcte pour le deuxième cavalier noir
	board[7][6]->setColor('N');

	// Initialisation des fous 'B's
	Fou* fouB1 = new Fou();
	board[0][2] = fouB1;
	board[0][2]->setColor('B');

	Fou* fouB2 = new Fou();
	board[0][5] = fouB2;  // Position correcte pour le deuxième fou 'B'
	board[0][5]->setColor('B');

	// Initialisation des fous noirs
	Fou* fouN1 = new Fou();
	board[7][2] = fouN1;  // Position correcte pour le premier fou noir
	board[7][2]->setColor('N');

	Fou* fouN2 = new Fou();
	board[7][5] = fouN2;  // Position correcte pour le deuxième fou noir
	board[7][5]->setColor('N');

	// Initialisation des reines
	Reine* reineB = new Reine();
	board[0][3] = reineB;
	board[0][3]->setColor('B');

	Reine* reineN = new Reine();
	board[7][3] = reineN;  // Position correcte pour la reine 'N'e
	board[7][3]->setColor('N');

	// Initialisation des rois
	Roi* roiB = new Roi();
	board[0][4] = roiB;
	board[0][4]->setColor('B');

	Roi* roiN = new Roi();
	board[7][4] = roiN;  // Position correcte pour le roi 'N'
	board[7][4]->setColor('N');

	// Initialisation des cases vides
	for (int y = 2; y < 6; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = nullptr;
		}
	}

#endif // VERSION_LIGHT
}

