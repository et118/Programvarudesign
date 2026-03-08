#include "../../../include/GameLogic/GameWorld/Scene.h"

Scene::Scene(std::string name) : name(name) {}

Scene::~Scene() {
    for(GameObject* object : this->objects) {
        delete object;
    }
    for(Character* character : this->characters) {
        delete character;
    }
}

GameObject* Scene::findGameObject(std::string &gameObjectName) {
    /* Returns a nullptr when object cant be found */
    for(GameObject* gameObject : this->objects) {
        if(gameObject->getName() == gameObjectName) {
            return gameObject;
        }
    }
    return nullptr;
}

Character* Scene::findCharacter(std::string &characterName) {
    for(Character* character : this->characters) {
        if(character->getName() == characterName) {
            return character;
        }
    }
    return nullptr;
}

bool Scene::isAvailable(std::string &theCharacter) {
    bool found = false;
    for(Character* character : this->characters) {
        if(character->getName() == theCharacter) {
            found = true;
            break;
        }
    }
    return found;
}

std::string Scene::getName() const { return this->name; }

std::vector<std::string> Scene::getCharacters()
{
    std::vector<std::string> returns;
    for (Character* character : this->characters)
    {
        returns.push_back(character->getName());
    }
    return returns;
}

std::vector<std::string> Scene::getObjects()
{
    std::vector<std::string> returns;
    for (GameObject* object : this->objects)
    {
        returns.push_back(object->getName());
    }
    return returns;
}
