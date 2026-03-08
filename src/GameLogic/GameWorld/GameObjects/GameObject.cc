#include "../../../../include/GameLogic/GameWorld/GameObjects/GameObject.h"
#include <stdexcept>

GameObject::GameObject(std::string name) : name(name) {}

GameObject::~GameObject() {
    for(InteractionType* type : interactionTypes) {
        delete type;
    }
}

std::vector<std::string> GameObject::listInteractionTypes() {
    std::vector<std::string> types;
    for(InteractionType* type : interactionTypes) {
        types.push_back(type->getName());
    }
    return types;
}

std::vector<std::string> GameObject::listInteractionOptions(std::string &interactionType) {
    std::vector<std::string> returns;
    for(InteractionType* type : interactionTypes) {
        returns.push_back(type->getName());
    }
    return returns;
}

std::vector<std::string> GameObject::selectInteraction(std::string &interactionType)  {
    for(InteractionType* type : interactionTypes) {
        if(type->getName() == interactionType) {
            this->currentInteraction = type;
            return type->getInteractionOptions();
        }
    }

    throw std::invalid_argument("Interaction not found: " + interactionType);

    /*
    std::vector<std::string> empty;
    return empty;

    used to return a empty vector - problem arose when writing unit tests
    Rock, Taste has no interactiontypes, meaning it returns a empty vector when it worked like it should
    But if this method couldnt find the interactionType, it would return a empty vector
    Essentially making it impossible to test for a positive/negative case

    Changing to throw when getting to the branch where it could not find a matching interactionType
    */
}

bool GameObject::setSelectedInteractionOption(std::string &option) {
    return this->currentInteraction->setOption(option);
}

std::string GameObject::startSelectedInteraction() {
    return this->currentInteraction->start();
}

std::string GameObject::getName() { return this->name; }
