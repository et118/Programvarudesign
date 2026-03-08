#include "../../include/UI/UserInterface.h"
#include "../../include/CharacterManagement/CharacterInterface.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <vector>

void UserInterface::print_slowly(std::string line) {
    for(char c : line) {
        if (c == '#') {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        } else {
            std::cout << c << std::flush;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void UserInterface::start(Game* game)
{   
    std::vector<std::string> gameObjects = game->getCurrentScene()->getObjects();
    std::vector<std::string> characters = game->getCurrentScene()->getCharacters();

    //Clear screen
    std::cout << "\033[2J\033[1;1H\n\n";

    std::cout<< "────────────────You find yourself in " + game->getCurrentSceneName() + "────────────────\n";
    print_slowly("\033[1mYou can see these characters:\033[0m\n");
    for(std::string character : characters) {
        print_slowly(">" + character + "\n");
    }
    print_slowly("\n\033[1mYou can also see these objects:\033[0m\n");
    for(std::string object : gameObjects) {
        print_slowly(">" + object + "\n");
    }

    print_slowly("\n\033[1mYour inventory contains the following:\033[0m\n");
    for(std::string object : game->getInventory()->getObjects()) {
        print_slowly(">" + object + "\n");
    }
    for(std::string character : game->getInventory()->getCharacters()) {
        print_slowly(">" + character + "\n");
    }

    int choice;
    while(true) {
        std::cout << "\n\n───────────────────What do you want to do?───────────────────\n";
        print_slowly("1) Interact with object\n");
        print_slowly("2) Interact with character\n");
        print_slowly("3) Exit the game\n");

        std::cin >> choice;
        if (choice == 1) {
            /*1) INTERACT WITH OBJECT
                see InteractWithObject.png
            */
            //Select object to interact with
            print_slowly("\n\033[1mWhich object do you wanna interact with?\033[0m\n");
            for(std::string object : gameObjects)
                print_slowly(">" + object + "\n");

            std::string chosenObject;
            while(std::count(gameObjects.begin(), gameObjects.end(), chosenObject) == 0) {
                getline(std::cin, chosenObject);
            }
            //Select what interaction to run
            print_slowly(std::string("\n\033[1mWhat do you wanna do with the ") + chosenObject + "?\033[0m\n");
            std::vector<std::string> interactions = game->selectObject(chosenObject);

            for(std::string interaction : interactions)
                print_slowly(">" + interaction + "\n");

            std::string chosenInteraction;
            while(std::count(interactions.begin(), interactions.end(), chosenInteraction) == 0) {
                getline(std::cin, chosenInteraction);
            }

            //Select interaction options (optional)
            std::vector<std::string> options = game->selectInteraction(chosenInteraction);
            if(options.size() > 0) {
                print_slowly("\n\033[1mPlease select an option\033[0m\n");
                for (int i = 0; i < options.size(); i++)
                    print_slowly( std::to_string(i) + ") " + options[i] + '\n');

                int option;
                while(true) {
                    std::cin >> option;
                    if (option < 0 || option > options.size() - 1) {
                        print_slowly("\033[1mInvalid option. Please try again\033[0m\n");
                    } else {
                        game->setInteractionOption(options[option]);
                        break;
                    }
                }
            }
            print_slowly(game->startInteraction());
        } else if (choice == 2) {
            /*2) INTERACT WITH CHARACTER
                see ms-interaction-diag-interact-with-character.png
            */

            //Select character to interact with
            print_slowly("\n\033[1mWhich character do you wanna interact with?\033[0m\n");
            for(std::string character : characters)
                print_slowly(">" + character + "\n");
            
            std::string chosenCharacter;
            while(std::count(characters.begin(), characters.end(), chosenCharacter) == 0) {
                getline(std::cin, chosenCharacter);
            }
            std::unique_ptr<CharacterInterface> interface = game->initiateConversation(chosenCharacter);
            std::vector<std::string> result = interface->activate();
            print_slowly(chosenCharacter + ": " + result[0]); //Printing the character greeting

            //Select dialogue option
            while(true) {
                print_slowly("\n\033[1mPlease select an option:\033[0m\n");
                print_slowly("0) Exit conversation\n");
                for(int i = 1; i < result.size(); i++)
                    print_slowly(std::to_string(i) + ") " + result[i] + "\n");

                int option;
                while(true) {
                    std::cin >> option;
                    if (option == 0) {
                        break;
                    } else if (option < 0 || option > result.size() - 1) {
                        print_slowly("\033[1mInvalid option. Please try again\033[0m\n");
                    } else {
                        result = interface->sendQuery(result[option]);
                        print_slowly(chosenCharacter + ": " + result[0]);
                        break;
                    }
                }
                if (option == 0) break;
            }
        } else if (choice == 3) {
            break;
        } else {
            print_slowly("\033[1mInvalid choice, please try again\033[0m\n");
        }
    }

}
