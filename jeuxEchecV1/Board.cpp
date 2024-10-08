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
			delete board[y][x];  // Lib�re la m�moire pour chaque pi�ce
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
		board[6][i] = pion;  // Correctement plac� en rang�e 6 pour les pions noirs
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
		board[7][i] = tour;  // Correctement plac� en rang�e 6 pour les pions noirs
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
		board[6][i] = pion;  // Correctement plac� en rang�e 6 pour les pions noirs
		board[6][i]->setColor('N');
	}

	// Initialisation des tours blanches
	Tour* tourB1 = new Tour();
	board[0][0] = tourB1;
	board[0][0]->setColor('B');

	Tour* tourB2 = new Tour();
	board[0][7] = tourB2;  // Position correcte pour la deuxi�me tour
	board[0][7]->setColor('B');

	// Initialisation des tours noires
	Tour* tourN1 = new Tour();
	board[7][0] = tourN1;  // Position correcte pour la premi�re tour noire
	board[7][0]->setColor('N');

	Tour* tourN2 = new Tour();
	board[7][7] = tourN2;  // Position correcte pour la deuxi�me tour noire
	board[7][7]->setColor('N');

	// Initialisation des cavaliers 'B's
	Cavalier* cavalierB1 = new Cavalier();
	board[0][1] = cavalierB1;
	board[0][1]->setColor('B');

	Cavalier* cavalierB2 = new Cavalier();
	board[0][6] = cavalierB2;  // Position correcte pour le deuxi�me cavalier 'B'
	board[0][6]->setColor('B');

	// Initialisation des cavaliers noirs
	Cavalier* cavalierN1 = new Cavalier();
	board[7][1] = cavalierN1;  // Position correcte pour le premier cavalier noir
	board[7][1]->setColor('N');

	Cavalier* cavalierN2 = new Cavalier();
	board[7][6] = cavalierN2;  // Position correcte pour le deuxi�me cavalier noir
	board[7][6]->setColor('N');

	// Initialisation des fous 'B's
	Fou* fouB1 = new Fou();
	board[0][2] = fouB1;
	board[0][2]->setColor('B');

	Fou* fouB2 = new Fou();
	board[0][5] = fouB2;  // Position correcte pour le deuxi�me fou 'B'
	board[0][5]->setColor('B');

	// Initialisation des fous noirs
	Fou* fouN1 = new Fou();
	board[7][2] = fouN1;  // Position correcte pour le premier fou noir
	board[7][2]->setColor('N');

	Fou* fouN2 = new Fou();
	board[7][5] = fouN2;  // Position correcte pour le deuxi�me fou noir
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

void Board::displayBoard()
{
	// Affiche les coordonn�es des colonnes
	std::cout << "  a b c d e f g h" << std::endl;
	std::cout << "  ----------------" << std::endl;

	for (int y = 0; y < 8; y++) {
		std::cout << 8 - y << "|";  // Affiche les num�ros des lignes

		for (int x = 0; x < 8; x++) {
			if (board[y][x] != nullptr) {
				// Appelle la m�thode virtuelle getPieceSymbol pour obtenir le symbole de la pi�ce
				std::cout << board[y][x]->getPieceSymbol();
			}
			else {
				// Si la case est vide
				std::cout << ".";
			}
			std::cout << " ";  // Ajoute un espace entre les symboles
		}

		std::cout << "|" << 8 - y << std::endl;  // Affiche les num�ros des lignes � droite
	}

	std::cout << "  ----------------" << std::endl;
	std::cout << "  a b c d e f g h" << std::endl;  // Affiche les lettres des colonnes
}

void Board::move()
{
	bool isGoodMove = false;
	while (!isGoodMove)
	{
		std::cout << "Entrez les coordonn�es de la pi�ce � d�placer (ex: a2): ";
		std::string coordDep;
		std::cin >> coordDep;

		int yDep = letterToNumber(coordDep[0]);
		int xDep = 8 - (coordDep[1] - '0');


		std::cout << "Entrez les coordonn�es de la case d'arriv�e (ex: a4): ";
		std::string coordArr;
		std::cin >> coordArr;

		int yArr = letterToNumber(coordArr[0]);
		int xArr = 8 - (coordArr[1] - '0');


		// V�rifie si la case de d�part contient une pi�ce
		if (board[xDep][yDep] == nullptr) {
			VERSION_LOG("Il n'y a pas de pi�ce � cet emplacement!");
			continue;
		}

		// V�rifie si la case d'arriv�e contient une pi�ce de la m�me couleur
		if (board[xArr][yArr] != nullptr && board[xDep][yDep]->getColor() == board[xArr][yArr]->getColor()) {
			VERSION_LOG("Vous ne pouvez pas d�placer votre pi�ce sur une case occup�e par une de vos pi�ces!");
			continue;
		}

		//Verifie si une piece n'est pas sur le chemin
		bool isPieceOnTheWay = false;
		//Mouvement vertical
		if (xDep == xArr) {
			if (yDep < yArr) {
				for (int i = yDep + 1; i < yArr; i++) {
					if (board[xDep][i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
			else {
				for (int i = yDep - 1; i > yArr; i--) {
					if (board[xDep][i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
		}
		//Movement horizontal
		else if (yDep == yArr) {
			if (xDep < xArr) {
				for (int i = xDep + 1; i < xArr; i++) {
					if (board[i][yDep] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
			else {
				for (int i = xDep - 1; i > xArr; i--) {
					if (board[i][yDep] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
		}
		//Movement diagonal
		else if (abs(xDep - xArr) == abs(yDep - yArr)) {
			if (xDep < xArr && yDep < yArr) {
				for (int i = 1; i < abs(xDep - xArr); i++) {
					if (board[xDep + i][yDep + i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
			else if (xDep < xArr && yDep > yArr) {
				for (int i = 1; i < abs(xDep - xArr); i++) {
					if (board[xDep + i][yDep - i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						isPieceOnTheWay = true;
						continue;
					}
				}
			}
			else if (xDep > xArr && yDep < yArr) {
				for (int i = 1; i < abs(xDep - xArr); i++) {
					if (board[xDep - i][yDep + i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						continue;
					}
				}
			}
			else {
				for (int i = 1; i < abs(xDep - xArr); i++) {
					if (board[xDep - i][yDep - i] != nullptr) {
						VERSION_LOG("Il y a une pi�ce sur le chemin!");
						continue;
					}
				}
			}
		}
		else {
			VERSION_LOG("Il y a une pi�ce sur le chemin!");
			continue;
		}

		if (isPieceOnTheWay) {
			continue;
		}

		// V�rifie si la case de d�part est la m�me que la case d'arriv�e
		if (xDep == xArr && yDep == yArr) {
			VERSION_LOG("Vous devez d�placer la pi�ce � un autre emplacement!");
			continue;
		}

		// V�rifie si les coordonn�es sont valides
		if (xDep < 0 || xDep > 7 || yDep < 0 || yDep > 7 || xArr < 0 || xArr > 7 || yArr < 0 || yArr > 7) {
			VERSION_LOG("Coordonn�es invalides!");
			continue;
		}

		// V�rifie si le d�placement est valide
		if (!board[xDep][yDep]->isValidMove(xDep, yDep, xArr, yArr)) {
			VERSION_LOG("D�placement invalide!");
			continue;
		}
		else
		{
			// D�place la pi�ce
			std::cout << "D�placement valide!" << std::endl;
			board[xArr][yArr] = board[xDep][yDep];
			board[xDep][yDep] = nullptr;
			isGoodMove = true;
		}
	}
}

int Board::letterToNumber(char letter)
{
	switch (letter)
	{
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	}
}
