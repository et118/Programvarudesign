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
    Character* findCharacter(std::string &characterName); //Extra utility function added
    bool isAvailable(std::string &theCharacter);
    std::string getName() const;
    std::vector<std::string> getCharacters(); //Returns the names of all characters
    std::vector<std::string> getObjects(); //Returns the names of all objects

};
