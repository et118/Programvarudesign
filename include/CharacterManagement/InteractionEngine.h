#pragma once
#include <string>
#include <vector>

//It's kinda weird how the provided interaction diagrams shows this as an object
//But we followed orders like good soldi... programmers
class InteractionEngine
{
private:
public:
    //This will only be a simple pass-through for this MVP
    std::string parseQuery(std::string theQuery);
    //This formats the response and options into a single vector, with the response at index 0
    std::vector<std::string> formatResponse(std::string theQuery, std::vector<std::string> nextConversationOptions);
};
