#include "../../include/CharacterManagement/Character.h"

Character::Character(std::string name, std::string initialGreeting) : name(name), initialGreeting(initialGreeting) {}

std::string Character::getInitialGreeting() {
    return this->initialGreeting;
}

std::string Character::getName() {
    return this->name;
}
