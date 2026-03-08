#include "../../../include/GameLogic/GameWorld/InventoryScene.h"

InventoryScene::InventoryScene() : Scene("Inventory")
{
    for(int i = 0; i < 3; i++) {
        this->objects.push_back(new Rock());
    }

    this->characters.push_back(new Character("Sherlock", "LET ME OUT OF HERE", {
        {{"LET ME OUT AAAAAAAA",""}}
    }));
}
