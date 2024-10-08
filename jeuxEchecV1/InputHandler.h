#pragma once
#include <utility>
class InputHandler
{
public:
    virtual std::pair<std::pair<int, int>, std::pair<int, int>> getMove() = 0;
    virtual ~InputHandler() = default;
};

