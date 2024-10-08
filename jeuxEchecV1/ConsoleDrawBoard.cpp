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
