/*********************************************************************
 ** Program Filename: Canteen.cpp
 ** Author: Diana Bacon
 ** Date: 2015-12-05
 ** Description: Implementation of the Canteen class.  Functions
 **   related to the derived class for Canteen spaces.
 *********************************************************************/

#include "Canteen.hpp"

/*********************************************************************
 ** Function: Canteen
 ** Description: Default constructor for the Canteen class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A Canteen object will be created. The items
 **   container is given a name and some items are added.
 *********************************************************************/
Canteen::Canteen()
{
    items->setName("Cash Register");
    items->add("German Reichsmarks", false);
    items->add("Lagergeld (camp money)", false);
    items->add("Monopoly money", false);
    items->add("British pounds", false);
}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into a Canteen space.
 ** Parameters: A pointer to an Airman object.
 ** Pre-Conditions: A Canteen object must exist.
 ** Post-Conditions:  You will be allowed access to cash register items
 **   if you offer to swap your cigarettes.
 *********************************************************************/
bool Canteen::enter(Airman *myAirman)
{
    std::cout << std::endl << "You are in " << getName() << std::endl;
    char choice = ' ';
    std::cout << "The guard offers you money for your cigarettes." << std::endl;
    std::cout << "Do you have any to trade?" << std::endl;
    std::cout << "y) yes" << std::endl;
    std::cout << "n) no" << std::endl;
    std::cout << "Enter y or n: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    if (choice == 'y') {
        return true;
    } else {
        return false;
    }
}