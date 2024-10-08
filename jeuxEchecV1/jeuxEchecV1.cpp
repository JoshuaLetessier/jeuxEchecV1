// jeuxEchecV1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Board.h"

#include "Define.h"




int main()
{
	Board board;
	board.initBoard();
	bool isGame = true;
	int demoCount = 0;
	while (isGame)
	{

		#ifdef VERSION_DEMO
				demoCount += 1;
				if (demoCount == 3)
				{
					std::cout << "mode démo fini" << std::endl;
					return 0;
				}
		#endif // VERSION_DEMO

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
