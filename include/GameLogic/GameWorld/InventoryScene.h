#pragma once
#include "./Scene.h"
#include "./GameObjects/Rock.h"

class InventoryScene : public Scene
{
private:
public:
    InventoryScene() : Scene("Inventory")
    {
        for(int i = 0; i < 386; i++) {
            this->objects.push_back(new Rock());
        }
    }

};
