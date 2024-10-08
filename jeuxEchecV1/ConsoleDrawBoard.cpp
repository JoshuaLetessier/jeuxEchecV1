#include "ConsoleDrawBoard.h"
#include <iostream>

ConsoleDrawBoard::ConsoleDrawBoard()
{
}

ConsoleDrawBoard::~ConsoleDrawBoard()
{
}

void ConsoleDrawBoard::drawBoard(PionGenerique* board[8][8])
{
	// Affiche les coordonnées des colonnes
	std::cout << "  a b c d e f g h" << std::endl;
	std::cout << "  ----------------" << std::endl;

	for (int y = 0; y < 8; y++) {
		std::cout << 8 - y << "|";  // Affiche les numéros des lignes

		for (int x = 0; x < 8; x++) {
			if (board[y][x] != nullptr) {
				// Appelle la méthode virtuelle getPieceSymbol pour obtenir le symbole de la pièce
				std::cout << board[y][x]->getPieceSymbol();
			}
			else {
				// Si la case est vide
				std::cout << ".";
			}
			std::cout << " ";  // Ajoute un espace entre les symboles
		}

		std::cout << "|" << 8 - y << std::endl;  // Affiche les numéros des lignes à droite
	}

	std::cout << "  ----------------" << std::endl;
	std::cout << "  a b c d e f g h" << std::endl;  // Affiche les lettres des colonnes
}
