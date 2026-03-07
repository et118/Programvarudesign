#pragma once
#include "./GameWorld/GameObjects/GameObject.h"
#include "../CharacterManagement/InteractionType.h"
#include "../CharacterManagement/CharacterInterface.h"
#include "./GameWorld/VolcanoScene.h"
#include "./GameWorld/InventoryScene.h"
#include "../UI/UserInterface.h"
#include "GameWorld/Scene.h"
#include <vector>
#include <string>
#include <memory>

// We removed the GameElement class because we do not need recursive scenes. :)
/*
Run file

Game describes where the player finds themselves.
Game describes the things around you in the scene.
Game presents possible actions:

1) INTERACT WITH OBJECT
    What object do you wanna interact with?  ________

    see InteractWithObject.png

2) INTERACT WITH CHARACTER
    What character do you wanna interact with? ______

    see ms-interaction-diag-interact-with-character.png


*/
class Game
{
private:
    GameObject* currentGameObject;
    Scene* currentScene;
    Scene* inventory;
public:
    Game();
    ~Game();
    std::vector<std::string> selectObject(std::string &gameObjectName);
    std::vector<std::string> selectInteraction(std::string &interactionType);
    // Since this is a minimal viable product
    // we have decided to change "setInteractionOptions" to be singular
    bool setInteractionOption(std::string &option);
    std::string startInteraction();
    std::unique_ptr<CharacterInterface> initiateConversation(std::string theCharacter);
    Scene* getCurrentScene();
    std::string getCurrentSceneName();
    Scene* getInventory();

};
