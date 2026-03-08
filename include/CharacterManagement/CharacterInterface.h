#pragma once
#include <string>
#include "Character.h"
#include <vector>
class CharacterInterface
{
private:
    Character* currentlyActive;
public:
    //Changed from std::string to a direct Character* to avoid CharacterRepository
    CharacterInterface(Character* theCharacter); 
    // Element 0 is the characters greeting, other elements are response options
    std::vector<std::string> activate(); 
    // Element 0 is always the characters response, other elements are response options
    std::vector<std::string> sendQuery(std::string &theQuery); 
};
