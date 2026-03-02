#include "GameObjects/GameObject.h"
#include "../CharacterManagement/InteractionType.h"
#include "GameWorld/Scene.h"
#include <vector>
#include <string>

class InteractionType;
class Game
{
private:
    GameObject* currentGameObject;
    Scene* currentScene;
public:
    std::vector<InteractionType> selectObject(std::string &gameObjectName);
    std::vector<std::string> selectInteraction(std::string &interactionType);
    // Since this is a minimal viable product
    // we have decided to change "setInteractionOptions" to be singular
    bool setInteractionOption(std::string option);
};
