#include "../../include/GameLogic/Game.h"
#include <string>
#include <vector>
#include <memory>

Game::Game()
{
    this->currentScene = new VolcanoScene();
    this->inventory = new InventoryScene();
}

Game::~Game() {
    delete this->currentScene;
    delete this->inventory;
}

std::vector<std::string> Game::selectObject(std::string &gameObjectName)
{
    this->currentGameObject = currentScene->findGameObject(gameObjectName);

    return currentGameObject->listInteractionTypes();
}

std::vector<std::string> Game::selectInteraction(std::string &interactionType)
{
    /*
    same name for methods in two different classes
    took me 30min to find why shit wasnt working
    the time is currently 00:47 and im hungry
    */
    return this->currentGameObject->selectInteraction(interactionType);
}

bool Game::setInteractionOption(std::string &option)
{
    return currentGameObject->setSelectedInteractionOption(option);
}

std::string Game::startInteraction()
{
    return currentGameObject->startSelectedInteraction();
}

std::unique_ptr<CharacterInterface> Game::initiateConversation(std::string theCharacter)
{
    /*
    when a player starts a conversation, game creates a characterinterface ig?
    if i understood it correctly, games only responsibility is to create it and own it
    thus the only implementation is actually creating it and returning it
    and leaving all logic for the interface in itself
    */
    return std::make_unique<CharacterInterface>(theCharacter);
}

Scene* Game::getCurrentScene()
{
    return this->currentScene;
}

std::string Game::getCurrentSceneName()
{
    return this->currentScene->getName();
}

Scene* Game::getInventory()
{
    return this->inventory;
}
