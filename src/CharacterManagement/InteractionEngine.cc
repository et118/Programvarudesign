#include "../../include/CharacterManagement/InteractionEngine.h"
#include <string>
#include <vector>

/*
InteractionEngine was one of those classes that looked really scary
But since we're working towards a MVP, parseQuery becomes mostly a pass through.

The architecture of the project suggests a future where parseQuery becomes smarter,
maybe where a player could free text write. parseQuery in that future would be quite advanced.
For now, the players gets a load of pre-chosen options for actions, so theres not much to parse.
*/

std::string InteractionEngine::parseQuery(std::string theQuery)
{
    return theQuery;
}

std::vector<std::string> InteractionEngine::formatResponse(
    std::string theQuery, std::vector<std::string> nextConversationOptions)
{
    // packing the response + conversation options for the UI to unpack
    std::vector<std::string> result;

    result.push_back(theQuery);
    for (auto option : nextConversationOptions)
        result.push_back(option);

    return result;
}
