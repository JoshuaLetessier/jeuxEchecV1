#include "Game.h"
#include <iostream>

#include "Define.h"
#include "ConsoleDrawBoard.h"
#include "ConsoleInputHandler.h"



Game::Game() :
	board(new Board()),
	movementValidator(new MovementValidator()),
	isGame(true),
	currentPlayer('B')
{
#ifdef VERSION_CONSOLE
	drawBoard = new ConsoleDrawBoard();
	inputHandler = new ConsoleInputHandler();
#elif defined(USE_SFML_DRAW_BOARD)
	drawBoard = new SFMLDrawBoard();
	inputHandler = new SFMLInputHandler();
#else
	drawBoard = nullptr;
	inputHandler = nullptr;
#endif

	if (!drawBoard || !inputHandler) {
		throw std::runtime_error("Erreur : aucune m�thode d'affichage ou d'input d�finie !");
	}
}

Game::~Game()
{
	if (board) delete board;
	if (drawBoard) delete drawBoard;
	if (inputHandler) delete inputHandler;
	if (movementValidator) delete movementValidator;
}

void Game::start()
{
	initGame();
	play();
	endGame();
}

void Game::initGame()
{
	board->initBoard();
}

void Game::play()
{
	while (isGame)
	{
		#ifdef VERSION_DEMO
				if (modeDemo())
				{
					break;
				}
		#endif // VERSION_DEMO

		clearScreen();
		std::cout << "Tour du joueur " << currentPlayer << std::endl;
		drawBoard->drawBoard(board->board);
		
		isGoodMove = false;
		while (!isGoodMove)
		{
			auto moves = inputHandler->getMove();

			if (movementValidator->Excute(moves.first.first, moves.first.second, moves.second.first, moves.second.second, board->board, currentPlayer))
			{
				switchPlayer();
				if (board->board[moves.second.first][moves.second.second] != nullptr) {
					delete board->board[moves.second.first][moves.second.second];  // Lib�re la m�moire de la pi�ce captur�e
				}
				board->board[moves.second.first][moves.second.second] = board->board[moves.first.first][moves.first.second];
				board->board[moves.first.first][moves.first.second] = nullptr;
				isGoodMove = true;
			}
			else
			{
				VERSION_LOG("Mouvement invalide");
			}
		}
	}
}

void Game::endGame()
{
}

void Game::switchPlayer()
{
	currentPlayer = currentPlayer == 'B' ? 'N' : 'B';
}

void Game::clearScreen()
{
	#ifdef _WIN32
		system("cls");  // Pour Windows
	#else
		system("clear");  // Pour Linux/macOS
	#endif
}

bool Game::modeDemo()
{
	demoCount += 1;
	if (demoCount == 3)
	{
		std::cout << "mode d�mo fini" << std::endl;
		return true;
	}

	return false;
}
