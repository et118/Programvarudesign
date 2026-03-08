#include "../../include/CharacterManagement/CharacterInterface.h"
#include "../../include/CharacterManagement/InputSanitiser.h"
CharacterInterface::CharacterInterface(Character* theCharacter) : currentlyActive(theCharacter) {
    //We dont use CharacterRepository so we instead just pass along the Character Pointer
}

std::vector<std::string> CharacterInterface::activate() {
    return this->currentlyActive->getInitialGreeting();
}

std::vector<std::string> CharacterInterface::sendQuery(std::string &theQuery) {
    return this->currentlyActive->query(InputSanitiser::sanitiseInput(theQuery));
}
