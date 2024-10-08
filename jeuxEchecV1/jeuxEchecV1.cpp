// jeuxEchecV1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Game.h"

#include "Define.h"

int main()
{
	Game* game = new Game();
	game->start();

#ifdef _DEBUG

	_CrtDumpMemoryLeaks();

#endif

	return 0;
}
