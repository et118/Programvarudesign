#pragma once
#include <string>
#include "GameObjects/GameObject.h"
#include "../../CharacterManagement/Character.h"

class Scene
{
protected:
    std::string name;
    std::vector<Character*> characters;
    std::vector<GameObject*> objects;

public:
    Scene(std::string name);
    GameObject* findGameObject(std::string &gameObjectName);
    bool isAvailable(std::string theCharacter);
    std::string getName() const { return this->name; }

    std::vector<std::string> getCharacters()
    {
        std::vector<std::string> returns;
        for (Character* character : this->characters)
        {
            returns.push_back(character->getName());
        }
        return returns;
    }

    std::vector<std::string> getObjects()
    {
        std::vector<std::string> returns;
        for (GameObject* object : this->objects)
        {
            returns.push_back(object->getName());
        }
        return returns;
    }

};
