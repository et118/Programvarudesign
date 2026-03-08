#include "../../../include/CharacterManagement/Interactions/Taste.h"

Taste::Taste(std::string description) : InteractionType("Taste"), description(description) {}

std::string Taste::start()
{
    return this->description;
}
