#include "../../include/CharacterManagement/Character.h"
#include "../../include/CharacterManagement/InteractionEngine.h"
#include "../../include/GameLogic/PlotEngine.h"
Character::Character(std::string name, std::string initialGreeting, std::vector<std::map<std::string, std::string>> conversationOptions) : name(name), initialGreeting(initialGreeting), conversationOptions(conversationOptions) {}

std::pair<std::string, std::vector<std::string>> Character::getResponseAndConversationOptions(int plotState, std::string parsedQuery) {
    if (plotState >= this->conversationOptions.size()) {
        plotState = this->conversationOptions.size()-1;
    }

    std::vector<std::string> conversationOptions;
    std::string response;
    for(auto& pair : this->conversationOptions.at(plotState)) {
        if(pair.first == parsedQuery) {
            response = pair.second;
        }
        conversationOptions.push_back(pair.first);
    }

    return {response, conversationOptions};
}

std::vector<std::string> Character::getInitialGreeting() {
    return this->query(this->initialGreeting); //we can just reuse the query() function to format everything right
}

std::vector<std::string> Character::query(std::string safeQuery) {
    InteractionEngine engine = InteractionEngine();

    std::string parsedQuery = engine.parseQuery(safeQuery);
    
    int plotState = PlotEngine::getInstance().getPlotState();
    
    std::pair<std::string, std::vector<std::string>> result = this->getResponseAndConversationOptions(plotState, parsedQuery);

    return engine.formatResponse(result.first, result.second);
}
std::string Character::getName() {
    return this->name;
}
