/*********************************************************************
 ** Program Filename: Game.hpp
 ** Author: Diana Bacon
 ** Date: 2015-12-02
 ** Description: Definition of the Game class.  High level
 **   control of Stalag Escape game, including unit tests.
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Barracks.hpp"
#include "Library.hpp"
#include "Canteen.hpp"
#include "PlayField.hpp"
#include "Tunnel.hpp"
#include "Forest.hpp"
#include "Airman.hpp"

class Game
{
private:
    Barracks *barracks;     // sleeping quarters
    Library *library;       // library building
    Canteen *canteen;       // camp store and food service
    Forest *forest;         // forest outside perimeter fence
    PlayField *playfield;   // playing field for sports
    Tunnel *tunnel;         // secret tunnel
    Airman *airman;         // the captured airman, our hero
    
public:
    Game();
    void displayTheme();
    void displayMap();
    void displaySolution();
    void play();
    ~Game();
    
    // unit tests
    void test_rucksack();
    void test_pointers();
    void test_navigation();
    void test_items();
    void test_actions();
};

#endif /* Game_hpp */
