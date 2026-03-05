#include "../../../include/GameLogic/GameWorld/VolcanoScene.h"
#include "../../../include/CharacterManagement/Character.h"
#include "../../../include/GameLogic/GameWorld/GameObjects/Rock.h"
#include "../../../include/GameLogic/GameWorld/GameObjects/Lava.h"
VolcanoScene::VolcanoScene()
    : Scene("Vesuvius")
{
    this->characters.push_back(new Character("Jonas", "Hej."));
    this->characters.push_back(new Character("Spider-Man", "Woah!"));
    this->characters.push_back(new Character("Fernando", "Mama mia!"));
    this->characters.push_back(new Character("Sherlock", "When you have eliminated the impossible, "
                                                          "whatever remains, however improbable, "
                                                          "must be the truth."));
    this->characters.push_back(new Character("Yapper", "According to all known laws of aviation,"
                                                        "there is no way a bee should be able to fly."));

    this->objects.push_back(new Rock());
    this->objects.push_back(new Lava());
}
