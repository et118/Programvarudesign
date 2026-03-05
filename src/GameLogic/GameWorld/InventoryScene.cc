#include "../../../include/GameLogic/GameWorld/InventoryScene.h"

InventoryScene::InventoryScene() : Scene("Inventory")
{
    for(int i = 0; i < 386; i++) {
        this->objects.push_back(new Rock());
    }
}
