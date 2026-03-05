#include "../../include/CharacterManagement/InteractionType.h"

std::vector<std::string> InteractionType::getInteractionOptions() { return this->interactionOptions; }

bool InteractionType::setOption(std::string &option) { this->selectedOption = option; }

std::string InteractionType::getName() { return this->name; }
