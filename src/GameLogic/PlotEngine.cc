#include "../../include/GameLogic/PlotEngine.h"

int PlotEngine::getPlotState()
{
    return this->currentPlotStep;
}

PlotEngine& PlotEngine::getInstance()
{
    static PlotEngine instance;
    return instance;
}

void PlotEngine::advancePlot()
{
    this->currentPlotStep += 1;
}
