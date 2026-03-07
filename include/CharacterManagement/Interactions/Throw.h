#pragma once
#include "../InteractionType.h"
#include <string>
class Throw : public InteractionType
{
private:
    std::string objectName;
public:
    Throw(std::string objectName);

    std::string start() override;

};
