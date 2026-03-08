#include "../../../../include/GameLogic/GameWorld/Interactions/Inspect.h"

Inspect::Inspect(std::string description) : InteractionType("Inspect"), description(description) {}

std::string Inspect::start() 
{
    return this->description;
}

