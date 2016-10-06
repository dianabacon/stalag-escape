/*********************************************************************
 ** Program Filename: Forest.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-29
 ** Description: Implementation of the Forest class.  Functions
 **   related to the derived class for Forest spaces.
 *********************************************************************/

#include "Airman.hpp"
#include "Forest.hpp"

/*********************************************************************
 ** Function: Forest
 ** Description: Default constructor for the Forest class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A Forest object will be created. The items
 **   container is given a name but no items are added.
 *********************************************************************/
Forest::Forest()
{
    items->setName("trees"); // you can't see the forest for the trees
}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into a Forest space.
 ** Parameters: A pointer to an Airman object.
 ** Pre-Conditions: A Forest object must exist.
 ** Post-Conditions:  Checks the airman's rucksack to see if it
 **   contains the required items and returns true if it does.
 *********************************************************************/
bool Forest::enter(Airman *myAirman)
{
    std::cout << std::endl << "You have reached " << getName() << std::endl;
    if (myAirman->inRucksack("silk map") &&
        myAirman->inRucksack("German Reichsmarks") &&
        myAirman->inRucksack("Compass") &&
        myAirman->inRucksack("Forged Identification")) {
        std::cout << "You are well-prepared! :-)" << std::endl;
        return true;
    } else {
        std::cout << "You are not well-prepared. :-(" << std::endl;
        return false;
    }
    
}