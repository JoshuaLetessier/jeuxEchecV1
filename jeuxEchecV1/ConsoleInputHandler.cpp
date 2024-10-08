#include "ConsoleInputHandler.h"
#include <string>
#include <iostream>

#include "Define.h"

std::pair<std::pair<int, int>, std::pair<int, int>> ConsoleInputHandler::getMove()
{
    std::string coordDep, coordArr;

    std::cout << "Entrez les coordonnées de la pièce à déplacer (ex: a2): ";
    std::cin >> coordDep;
    auto startPos = std::make_pair(8 - (coordDep[1] - '0'), letterToNumber(coordDep[0]));

    std::cout << "Entrez les coordonnées de la case d'arrivée (ex: a4): ";
    std::cin >> coordArr;
    auto endPos = std::make_pair(8 - (coordArr[1] - '0'), letterToNumber(coordArr[0]));

    return { startPos, endPos };
}

int ConsoleInputHandler::letterToNumber(char letter)
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

