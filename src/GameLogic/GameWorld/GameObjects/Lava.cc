#include "../../../../include/GameLogic/GameWorld/GameObjects/Lava.h"

Lava::Lava() : GameObject("Lava")
{
    this->interactionTypes.push_back(new Inspect("HotHotHotHotHotHot!!@@@@"));
    this->interactionTypes.push_back(new Taste("You violently burn your tongue trying to taste the magma.\n-1 Speech."));
}
