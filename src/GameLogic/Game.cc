#include "../../include/GameLogic/Game.h"

Game::Game()
{
    this->currentScene = new VolcanoScene();
    this->inventory = new InventoryScene();
}

Game::~Game() {
    delete this->currentScene;
    delete this->inventory;
}

std::string Game::getCurrentSceneName() { return this->currentScene->getName(); }
