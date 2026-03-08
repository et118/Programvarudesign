#pragma once
#include "../InteractionType.h"
#include <vector>
#include <string>
class GameObject
{
protected:
    std::string name;
    std::vector<InteractionType*> interactionTypes;
    InteractionType* currentInteraction;
public:
    GameObject(std::string name);
    ~GameObject();
    // Changed named from "getInteractionTypes()"
    // See selectObject.png in docs
    std::vector<std::string> listInteractionTypes();
    // Changed name from "selectInteraction()""
    // See selectInteraction.png in docs
    std::vector<std::string> listInteractionOptions(std::string &interactionType);
    std::vector<std::string> selectInteraction(std::string &interactionType);
    bool setSelectedInteractionOption(std::string &option);
    std::string startSelectedInteraction();
    std::string getName();
};
