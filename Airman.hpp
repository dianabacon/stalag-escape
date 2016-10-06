/*********************************************************************
 ** Program Filename: Airman.hpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Definition of the Airman class.  Functions
 **   controlling actions of the airman character in the game.
 *********************************************************************/

#ifndef Airman_hpp
#define Airman_hpp

#include <iostream>
#include "Container.hpp"

//class Space;
#include "Space.hpp"

class Airman
{
private:
    Space *location;        // current location
    Space *last;            // previous location
    Container *rucksack;    // container to hold items

public:
    Airman();
    Space* getLocation();
    Space* lastLocation();
    void setLocation(Space*);
    std::string removeRucksack();
    bool addRucksack(std::string);
    bool inRucksack(std::string);
    void lookRucksack();
    void lookAround();
    void decide();
    void move();
    void pickUp();
    void putDown();
    ~Airman();
};

#endif /* Airman_hpp */
