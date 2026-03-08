#include "../../include/GameLogic/Game.h"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

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

    if (this->currentGameObject == nullptr)
        throw std::invalid_argument("Object not found: " + gameObjectName);

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
    if (!this->currentScene->isAvailable(theCharacter)) return nullptr;

    /* PhoneBook::getInstance().getContactMethod(theCharacter) Removed check because we dont use phonebook in this implementation*/

    /* We moved activate() outside of this function, since it will return a response, and this function is only responsible for creating the CharacterInterface */

    return std::make_unique<CharacterInterface>(this->currentScene->findCharacter(theCharacter));
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
