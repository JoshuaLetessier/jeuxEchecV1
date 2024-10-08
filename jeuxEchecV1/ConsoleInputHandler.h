#pragma once
#include "InputHandler.h"
class ConsoleInputHandler : public InputHandler
{
public:
	std::pair<std::pair<int, int>, std::pair<int, int>> getMove() override;
	~ConsoleInputHandler() = default;

private:
	int letterToNumber(char letter);
};

