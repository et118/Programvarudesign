#pragma once
#include <string>
#include <vector>

class InteractionType
{
private:

public:
    virtual std::vector<std::string> getInteractionOptions() = 0;
    virtual bool setOption(std::string &option) = 0;
};
