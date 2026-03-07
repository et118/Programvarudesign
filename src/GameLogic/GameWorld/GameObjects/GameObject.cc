#include "../../../../include/GameLogic/GameWorld/GameObjects/GameObject.h"

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
    std::vector<std::string> empty;
    return empty;
}

bool GameObject::setSelectedInteractionOption(std::string &option) {
    this->currentInteraction->setOption(option);
}

std::string GameObject::startSelectedInteraction() {
    return this->currentInteraction->start();
}

std::string GameObject::getName() { return this->name; }
