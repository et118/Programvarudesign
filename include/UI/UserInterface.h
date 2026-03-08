#pragma once
#include <string>
#include "../../include/GameLogic/Game.h"
class UserInterface
{
private:
    void print_slowly(std::string line);
public:
    void start(Game* game);
};
