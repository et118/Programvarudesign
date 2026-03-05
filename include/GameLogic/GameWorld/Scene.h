#pragma once
#include <string>
#include <vector>
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
    std::string getName() const;
    std::vector<std::string> getCharacters();
    std::vector<std::string> getObjects();

};
