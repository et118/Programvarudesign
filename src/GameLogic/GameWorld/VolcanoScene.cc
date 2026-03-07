#include "../../../include/GameLogic/GameWorld/VolcanoScene.h"
#include "../../../include/CharacterManagement/Character.h"
#include "../../../include/GameLogic/GameWorld/GameObjects/Rock.h"
#include "../../../include/GameLogic/GameWorld/GameObjects/Lava.h"
VolcanoScene::VolcanoScene()
    : Scene("Vesuvius")
{
    this->characters.push_back(new Character("Jonas", "Hej.", {
        //At plotState 0
        {
            {"Who are you?", "I'm Jonas ofcourse"},
            {"Why are you here in this Volcano?", "I dunno, I tried to finish my morning coffee and then I suddenly found myself here"},
            {"Hej på dig", "Hej på dig med"},
            {"Så... hur är det med frugan?", "lika dåligt som vanligt :("},
            {"Ouch, jag ska nog lämna dig här då", "..."}
        },
        //At plotState 1
        {
            {"WHAT IS HAPPENING?", "JAG HAR INGEN ANING AAAAAAAA"}
        }
    }));
    this->characters.push_back(new Character("Spider-Man", "Woah!", {
        {
            {"Hey man, uhm, are you spiderman?", "Yes, wassup? Who else would I be?"},
            {"Why are you in this volcano?", "No clue. I was on my way home to aunt May, and then I just found myself here. #.#.#\nSomething mysterious is going on"}
        }
    }));

    this->objects.push_back(new Rock());
    this->objects.push_back(new Lava());
}
