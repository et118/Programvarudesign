#include "../../include/CharacterManagement/InteractionEngine.h"
#include <string>
#include <vector>

std::string InteractionEngine::parseQuery(std::string theQuery) { return theQuery; }

std::vector<std::string> InteractionEngine::formatResponse(
    std::string theQuery, std::vector<std::string> nextConversationOptions)
{
    std::vector<std::string> result;

    result.push_back(theQuery);
    for (auto option : nextConversationOptions)
        result.push_back(option);

    return result;
}
