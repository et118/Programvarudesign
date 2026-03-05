#include "../../../../include/GameLogic/GameWorld/GameObjects/Rock.h"

Rock::Rock() : GameObject("Rock")
{
    this->interactionTypes.push_back(new Inspect("It's a rock. ###.###.###.### What did you expect?"));
    this->interactionTypes.push_back(new Throw(this->getName()));
    this->interactionTypes.push_back(new Taste("This wasnt what Rock Candy was supposed to taste liek!"));
}
