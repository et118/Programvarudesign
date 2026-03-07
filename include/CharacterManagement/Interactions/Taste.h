#pragma once
#include "../InteractionType.h"
#include <string>
class Taste : public InteractionType
{
private:
    std::string description;
public:
    Taste(std::string description);

    std::string start() override;

};
