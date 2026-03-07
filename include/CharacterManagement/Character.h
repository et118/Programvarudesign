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

    //Extra help function returning response at index 0, and options
    std::pair<std::string, std::vector<std::string>> getResponseAndConversationOptions(int plotState, std::string parsedQuery); 
public:
    Character(std::string name, std::string initialGreeting, std::vector<std::map<std::string, std::string>> conversationOptions);
    std::vector<std::string> getInitialGreeting();
    std::vector<std::string> query(std::string safeQuery);
    std::string getName();
};
