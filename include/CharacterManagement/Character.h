#pragma once
#include <string>
#include <vector>
#include <map>
class Character
{
private:
    std::string name;
    std::string initialGreeting;
    std::vector<std::map<std::string, std::string>> conversationOptions;

    //Extra help function returning response at index 0, and options at the other indexes
    std::pair<std::string, std::vector<std::string>> getResponseAndConversationOptions(int plotState, std::string parsedQuery); 
public:
    Character(std::string name, std::string initialGreeting, std::vector<std::map<std::string, std::string>> conversationOptions);
    std::vector<std::string> getInitialGreeting(); //Instead of just returning a string, we treat it as a query and return followup conversation options
    std::vector<std::string> query(std::string safeQuery);
    std::string getName();
};
