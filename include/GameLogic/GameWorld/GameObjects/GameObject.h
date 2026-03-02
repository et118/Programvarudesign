#include "../../../CharacterManagement/InteractionType.h"
#include <vector>
class GameObject
{
private:
    InteractionType* currentInteraction;
public:
    // Changed named from "getInteractionTypes()"
    // See selectObject.png in docs
    std::vector<std::string> listInteractionTypes();

    // Changed name from "selectInteraction()""
    // See selectInteraction.png in docs
    std::vector<std::string> listInteractionOptions(std::string &interactionType);

    std::vector<std::string> selectInteraction(std::string &interactionType);

    bool setSelectedInteractionOption(std::string &option);

    std::string startSelectedInteraction();



};
