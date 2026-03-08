#pragma once
#include "./GameWorld/GameObjects/GameObject.h"
#include "GameWorld/InteractionType.h"
#include "../CharacterManagement/CharacterInterface.h"
#include "./GameWorld/VolcanoScene.h"
#include "./GameWorld/InventoryScene.h"
#include "GameWorld/Scene.h"
#include <vector>
#include <string>
#include <memory>

// We removed the GameElement class, since its unecessary to treat Scenes the same way as GameObjects in this MVP
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
    // we have decided to change "setInteractionOptions" to be singular for this MVPs
    bool setInteractionOption(std::string &option);
    std::string startInteraction();
    std::unique_ptr<CharacterInterface> initiateConversation(std::string theCharacter);
    Scene* getCurrentScene();
    std::string getCurrentSceneName();
    Scene* getInventory();

};
