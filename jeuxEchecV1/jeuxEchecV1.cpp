// jeuxEchecV1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Board.h"

int main()
{
    std::cout << "Hello World!\n";

	Board board;
	board.initBoard();
	bool isGame = true;
	while (isGame)
	{
		// Efface l'écran
		#ifdef _WIN32
				system("cls");  // Pour Windows
		#else
				system("clear");  // Pour Linux/macOS
		#endif

		board.displayBoard();

		board.move();
	}

	return 0;
}
