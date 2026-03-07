#include "../../include/CharacterManagement/CharacterInterface.h"
#include "../../include/CharacterManagement/InputSanitiser.h"
CharacterInterface::CharacterInterface(Character* theCharacter) : currentlyActive(theCharacter) {}

std::vector<std::string> CharacterInterface::activate() {
    return this->currentlyActive->getInitialGreeting();
}

std::vector<std::string> CharacterInterface::sendQuery(std::string &theQuery) {
    return this->currentlyActive->query(InputSanitiser::sanitiseInput(theQuery));
}
