#pragma once
#include "../InteractionType.h"
#include <string>
class Inspect : public InteractionType
{
private:
    std::string description;
public:
    Inspect(std::string description);

    std::string start() override;

};
