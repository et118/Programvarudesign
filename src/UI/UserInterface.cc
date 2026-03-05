#include "../../include/UI/UserInterface.h"
#include "../../include/CharacterManagement/CharacterInterface.h"
#include "../../include/GameLogic/Game.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <vector>

void UserInterface::print_slowly(std::string line) {
    for(char c : line) {
        if (c != '#') {
            std::cout << c << std::flush;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void UserInterface::start()
{
    Game game = Game();

    while (true)
    {
        std::vector<std::string> gameObjects = game.getCurrentScene()->getObjects();
        std::vector<std::string> characters = game.getCurrentScene()->getCharacters();

        std::cout << "You find yourself in " << game.getCurrentSceneName() << "\n";
        std::cout << "---In the room you see these characters:---\n";
        for(std::string character : characters) {
            std::cout << character << "\n";
        }
        std::cout << "---You can also see these objects:---\n";
        for(std::string object : gameObjects) {
            std::cout << object << "\n";
        }

        std::cout << "---What do you want to do?---\n";
        std::cout << "1) Interact with object\n";
        std::cout << "2) Interact with character\n";
        std::cout << "3) Exit the game\n";

        int choice;
        while(true) {
            std::cin >> choice;
            if (choice == 1) {
                /*1) INTERACT WITH OBJECT
                    see InteractWithObject.png
                */
                //Select object to interact with
                print_slowly("---Which object do you wanna interact with?---\n");
                for(std::string object : gameObjects)
                    std::cout << "-" << object << "\n";

                std::string chosenObject;
                while(std::count(gameObjects.begin(), gameObjects.end(), chosenObject) == 0) {
                    getline(std::cin, chosenObject);
                }
                //Select what interaction to run
                print_slowly(std::string("---What do you wanna do with the ") + chosenObject + "?---\n");
                std::vector<std::string> interactions = game.selectObject(chosenObject);

                for(std::string interaction : interactions)
                    std::cout << "-" << interaction << "\n";

                std::string chosenInteraction;
                while(std::count(interactions.begin(), interactions.end(), chosenInteraction) == 0) {
                    getline(std::cin, chosenInteraction);
                }

                //Select interaction options (optional)
                std::vector<std::string> options = game.selectInteraction(chosenInteraction);
                if(options.size() > 0) {
                    print_slowly("---Please select an option---");
                    for (int i = 0; i < options.size(); i++)
                        std::cout << i << ") " << options[i] << std::endl;

                    int option;
                    while(true) {
                        std::cin >> option;
                        if (option < 0 || option > options.size() - 1) {
                            std::cout << "Invalid option. Please try again\n";
                        } else {
                            game.setInteractionOption(options[option]);
                            break;
                        }
                    }
                }
                print_slowly(game.startInteraction());
            } else if (choice == 2) {
                /*2) INTERACT WITH CHARACTER
                    see ms-interaction-diag-interact-with-character.png
                */

                //Select character to interact with
                print_slowly("---Which character do you wanna interact with?---\n");
                for(std::string character : characters)
                    std::cout << "-" << character << "\n";
                
                std::string chosenCharacter;
                while(std::count(characters.begin(), characters.end(), chosenCharacter) == 0) {
                    getline(std::cin, chosenCharacter);
                }
                std::unique_ptr<CharacterInterface> interface = game.initiateConversation(chosenCharacter);
                std::vector<std::string> result = interface->activate();
                print_slowly(chosenCharacter + ": " + result[0]); //Printing the character greeting
                
                //Select dialogue option
                while(true) {
                    std::cout << "---Options---\n";
                    std::cout << "0) Exit conversation\n";
                    for(int i = 1; i < result.size(); i++)
                        std::cout << i << ") " << result[i] << "\n";

                    int option;
                    while(true) {
                        std::cin >> option;
                        if (option == 0) {
                            break;
                        } else if (option < 0 || option > result.size() - 1) {
                            std::cout << "Invalid option. Please try again\n";
                        } else {
                            result = interface->sendQuery(result[option]);
                            print_slowly(result[0]);
                            break;
                        }
                    }
                    if (option == 0) break;
                }
            } else if (choice == 3) {
                break;
            } else {
                std::cout << "Invalid choice, please try again" << std::endl;
            }
        }
    }
}
