#include <iostream>
#include "../include/GameLogic/Game.h"
#include "../include/UI/UserInterface.h"

/*
    UserInterface will handle the game loop because
    Game does nothing without user input
*/

int main(int argc, char* argv[]) {

    UserInterface ui;
    ui.start();
    return 0;
}
