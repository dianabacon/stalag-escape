/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-27
 ** Description: Main driver program for Stalag Escape game.
 ** Input: Menu driven input giving user a choice to see solution,
 **   run a selection of unit tests, or play the game
 ** Output: Text based output describing progress through game world.
 *********************************************************************/

#include "Game.hpp"

int main(int argc, const char * argv[]) {
    
    Game game;
    char choice = ' ';
    
    game.displayTheme();
    game.displayMap();
    
    std::cout << "What would you like to do? " << std::endl;
    std::cout << "p) Play game" << std::endl;
    std::cout << "s) Display solution" << std::endl;
    std::cout << "t) Run unit tests" << std::endl;
    std::cout << "Enter p, s, or t: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    switch (choice) {
        case 'p':
            game.play();
            break;
        case 's':
            game.displaySolution();
            break;
        case 't':
            char test;
            std::cout << "Which test do you want to run?" << std::endl;
            std::cout << "1) Test Container" << std::endl;
            std::cout << "2) Test Pointers" << std::endl;
            std::cout << "3) Test Navigation" << std::endl;
            std::cout << "4) Test Gathering Items" << std::endl;
            std::cout << "5) Test Special Actions" << std::endl;
            std::cout << "Enter 1 - 5: ";
            std::cin >> test;
            switch (test) {
                case '1':
                    game.test_rucksack();
                    break;
                case '2':
                    game.test_pointers();
                    break;
                case '3':
                    game.test_navigation();
                    break;
                case '4':
                    game.test_items();
                    break;
                case '5':
                    game.test_actions();
                    break;
                    
                default:
                    break;
            }
            break;
            
        default:
            break;
    }
    return 0;
}
