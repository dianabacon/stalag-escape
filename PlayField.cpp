/*********************************************************************
 ** Program Filename: PlayField.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Implementation of the PlayField class.  Functions
 **   related to the derived class for PlayField spaces.
 *********************************************************************/

#include "PlayField.hpp"

/*********************************************************************
 ** Function: PlayField
 ** Description: Default constructor for the PlayField class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A PlayField object will be created. The items
 **   container is given a name and an item is added.
 *********************************************************************/
PlayField::PlayField()
{
    items->setName("Wooden Horse");
    items->add("Compass", false);
}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into a PlayField space.
 ** Parameters: A pointer to an Airman object.
 ** Pre-Conditions: A PlayField object must exist.
 ** Post-Conditions:  If you choose to do gymnastics you gain access to
 **   the secret tunnel via the wooden horse, which also contains a
 **   compass.
 *********************************************************************/
bool PlayField::enter(Airman *myAirman)
{
    std::cout << std::endl << "You are in " << getName() << std::endl;
    char choice = ' ';
    std::cout << "Which sport would you like to play?" << std::endl;
    std::cout << "s) soccer" << std::endl;
    std::cout << "g) gymnastics" << std::endl;
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    if (choice == 'g') {
        std::cout << "You hide in the wooden horse and use the" << std::endl;
        std::cout << "trapdoor to access to the secret tunnel." << std::endl;
        openExit(5); // open secret tunnel
        return true;
    } else {
        std::cout << "You have fun playing soccer." << std::endl;
        closeExit(5); // close secret tunnel
        return false;
    }
}