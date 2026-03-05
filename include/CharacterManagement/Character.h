#pragma once
#include <string>
#include <vector>
class Character
{
private:
    std::string name;
    std::string initialGreeting;
public:
    Character(std::string name, std::string initialGreeting);
    std::string getInitialGreeting();
    std::vector<std::string> query(std::string safeQuery);
    std::string getName();
};
