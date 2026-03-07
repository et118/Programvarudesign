#include "../../include/CharacterManagement/InteractionType.h"

InteractionType::InteractionType(std::string name) : name(name) {}

std::vector<std::string> InteractionType::getInteractionOptions() { return this->interactionOptions; }

bool InteractionType::setOption(std::string &option) { 
    for(std::string& item : this->interactionOptions) {
        if (item == option) {
            this->selectedOption = option; 
            return true;
        }
    }
    return false;
}

std::string InteractionType::getName() { return this->name; }
