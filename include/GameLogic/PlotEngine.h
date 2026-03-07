#pragma once
#include <string>
class PlotEngine
{
private:
    int currentPlotStep = 0;
public:
    int getPlotState(); //used to return string, changed to int
    static PlotEngine& getInstance();
    void advancePlot();
};
