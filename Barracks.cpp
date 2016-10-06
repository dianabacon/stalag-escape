/*********************************************************************
 ** Program Filename: Barracks.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Implementation of the Barracks class.  Functions
 **   related to the derived class for Barracks spaces.
 *********************************************************************/

#include "Barracks.hpp"

/*********************************************************************
 ** Function: Barracks
 ** Description: Default constructor for the Barracks class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A Barracks object will be created. The items
 **   container is given a name and some items are added.
 *********************************************************************/
Barracks::Barracks()
{
    items->setName("Monopoly Game");
    items->add("silk map", false);
    items->add("monopoly money", false);
    items->add("race car", false);
    items->add("plastic houses", false);
    lightOn = false;
}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into a Barracks space.
 ** Parameters: A pointer to an Airman object.
 ** Pre-Conditions: A Barracks object must exist.
 ** Post-Conditions:  The light will be turned on (true) or off (false).
 *********************************************************************/
bool Barracks::enter(Airman *myAirman)
{
    std::cout << std::endl << "You are in " << getName() << std::endl;
 
    char choice = ' ';
    if (lightOn) {
        std::cout << "The light is on." << std::endl;
        std::cout << "Do you want to turn it off (y or n)?";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        if (choice == 'y') {
            lightOn = false;
            return false;
        } else {
            return true;
        }
    } else {
        std::cout << "The light is off." << std::endl;
        std::cout << "Do you want to turn it on (y or n)? ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        if (choice == 'y') {
            lightOn = true;
            return true;
        } else {
            return false;
        }
    }
}