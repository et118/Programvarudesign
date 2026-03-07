#pragma once
#include <string>
#include <vector>

/*
    Populate the "interactionOptions" membervariable in the ctor
    getInteractionOptions returns this list of strings
    setOption selects one of the options (sets the selectedOption membervariable)
    start() starts the interaction.
*/


class InteractionType
{
protected:
    std::string name;
    std::string selectedOption = "";
    std::vector<std::string> interactionOptions;
public:
    InteractionType(std::string name);

    std::vector<std::string> getInteractionOptions();
    bool setOption(std::string &option);
    virtual std::string start() = 0;
    std::string getName();
};
