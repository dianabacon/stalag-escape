/*********************************************************************
 ** Program Filename: Tunnel.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Implementation of the Tunnel class.  Functions
 **   related to the derived class for Tunnel spaces.
 *********************************************************************/

#include "Tunnel.hpp"

/*********************************************************************
 ** Function: Tunnel
 ** Description: Constructor for the Tunnel class
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A Tunnel object will be created. Some dirt is
 **   added and the items container is given a name but no items.
 *********************************************************************/
Tunnel::Tunnel()
{
    items->setName("ground");
    dirt = 2;
}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into Tunnel space.  You must help dig
 **   out the tunnel.
 ** Parameters: Pointer to airman.
 ** Pre-Conditions: Tunnel object must exist.
 ** Post-Conditions: You will be allowed access to forest exit when
 **   dirt = 0, it is decremented each time you elect to dig.
 *********************************************************************/
bool Tunnel::enter(Airman *myAirman)
{
    std::cout << std::endl << "You are in " << getName() << std::endl;

    char choice = ' ';
    if (dirt > 0) {
         std::cout << "There are " << dirt << " tons of dirt left in "
        << getName() << std::endl;
        std::cout << "Would you like to help dig? (y or n) ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        if (choice == 'y') {
            dirt--;
        }
        closeExit(3); // exit to forest is blocked
        return false;
    } else {
        std::cout << "You have cleared " << getName() << std::endl;
        openExit(3); // exit to forest is open
        return true;
    }
}