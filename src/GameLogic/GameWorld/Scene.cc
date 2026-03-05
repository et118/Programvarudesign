#include "../../../include/GameLogic/GameWorld/Scene.h"

Scene::Scene(std::string name) : name(name) {}

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
