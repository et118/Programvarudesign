#pragma once
#include <string>
#include <vector>

class InteractionType
{
protected:
    std::string name;
    std::string selectedOption = "";
    std::vector<std::string> interactionOptions;
public:
    InteractionType(std::string name);
    virtual ~InteractionType() = default;

    std::vector<std::string> getInteractionOptions();
    //For this MVP we decided to only allow one option to be set.
    bool setOption(std::string &option);
    virtual std::string start() = 0;
    std::string getName();
};
