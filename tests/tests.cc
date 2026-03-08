#define CATCH_CONFIG_MAIN // catch2 needs this to generate a main()
#include "../vendor/catch.hpp"
#include "../include/GameLogic/Game.h"

TEST_CASE("selectObject returns interactions for a valid object")
{
    // Setup
    Game game;

    // Act
    std::string objectName = "Rock";
    std::vector<std::string> result = game.selectObject(objectName);

    // Assert
    REQUIRE(result.size() == 3); // size of the vector selectObject("Rock") returns
    REQUIRE(result[0] == "Inspect");
    REQUIRE(result[1] == "Throw");
    REQUIRE(result[2] == "Taste");
}

TEST_CASE("selectObject throws when object does not exist")
{
    Game game;
    std::string objectName = "Banana";

    REQUIRE_THROWS(game.selectObject(objectName)); // passes if it throws
}

TEST_CASE("selectInteraction returns options for a valid interaction")
{
    // Ordering is important, selectObject() NEEDS to happen befoer selectInteraction()
    // Thus the setup includes
    Game game;
    std::string objectName = "Rock";
    game.selectObject(objectName);

    // This test tries to do Rock, Taste
    // This selectInteraction() should return a vector of strings with 1 element
    // [0] should be "This wasnt what Rock Candy was supposed to taste liek!"
    std::string interactionType = "Taste";
    std::vector<std::string> result = game.selectInteraction(interactionType);

    REQUIRE(result.size() == 0); // Taste has no options
}

TEST_CASE("selectInteraction throws when interaction does not exist")
{
    Game game;
    std::string objectName = "Rock";
    game.selectObject(objectName);

    std::string badInteractionType = "Swat";
    REQUIRE_THROWS(game.selectInteraction(badInteractionType));
}

TEST_CASE("setInteractionOption returns true for a valid option")
{
    // SETUP
    Game game;
    std::string gameObject = "Rock";
    std::string interactionType = "Throw";

    game.selectObject(gameObject);
    game.selectInteraction(interactionType);

    // ACT
    std::string option = "Throw like your bones will shatter.";
    bool result = game.setInteractionOption(option);

    // ASSERT
    REQUIRE(result == true);
}

TEST_CASE("setInteractionOption returns false for an invalid option")
{
    // SETUP
    Game game;
    std::string gameObject = "Rock";
    std::string interactionType = "Throw";

    game.selectObject(gameObject);
    game.selectInteraction(interactionType);

    // ACT
    std::string option = "Throw it, but silly!";
    bool result = game.setInteractionOption(option);

    // ASSERT
    REQUIRE(result == false);
}

TEST_CASE("startInteraction returns the correct result")
{
    // SETUP
    Game game;
    std::string gameObject = "Rock";
    std::string interactionType = "Throw";
    std::string option = "Throw like your bones will shatter.";

    game.selectObject(gameObject);
    game.selectInteraction(interactionType);
    game.setInteractionOption(option);

    // ACT
    std::string result = game.startInteraction();

    // ASSERT
    REQUIRE(result == "The Rock flies away like Team Rocket, never to be seen again.");
}

TEST_CASE("startInteraction returns empty string when invalid option is set")
{
    // SETUP
    Game game;
    std::string gameObject = "Rock";
    std::string interactionType = "Throw";
    std::string option = "Yeet it!";

    game.selectObject(gameObject);
    game.selectInteraction(interactionType);
    game.setInteractionOption(option);

    // ACT
    std::string result = game.startInteraction();

    // ASSERT
    REQUIRE(result == "");
}
