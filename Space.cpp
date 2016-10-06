/*********************************************************************
 ** Program Filename: Space.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-27
 ** Description: Implementation of the Space class.  Functions
 **   related to the abstract base class for spaces.
 *********************************************************************/

#include "Space.hpp"
#include "Airman.hpp"

/*********************************************************************
 ** Function: Space
 ** Description: Default constructor for the space class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: The constructor of the derived class will be 
 **   called and an object of the derived class will be created with
 **   a container of items.
 *********************************************************************/
Space::Space()
{
    items = new Container;
}

/*********************************************************************
 ** Function: setName
 ** Description: Set the value of the space's name.
 ** Parameters: A string n.
 ** Pre-Conditions: An object of a derived class must exist.
 ** Post-Conditions: The name variable will be set to the string n.
 *********************************************************************/
void Space::setName(std::string n)
{
    name = n;
}

/*********************************************************************
 ** Function: getName
 ** Description: Get the value of the space's name.
 ** Parameters:
 ** Pre-Conditions: An object of a derived class must exist.
 ** Post-Conditions: A string with the name of the space will be returned.
 *********************************************************************/
std::string Space::getName()
{
    return name;
}

/*********************************************************************
 ** Function: setExit
 ** Description: Adds another exit to the space.
 ** Parameters: A Space pointer s1, a string s2 with a desccription of
 **   the exit, and a bool o which holds the open/closed state of the
 **   exit.
 ** Pre-Conditions: An object of a derived class must exist.
 ** Post-Conditions: A pointer to a new Exit object will be added to
 **   the exits of the space.
 *********************************************************************/
void Space::setExit(Space* s1,std::string s2, bool o)
{
    exits.push_back(Exit(s1,s2,o));
}

/*********************************************************************
 ** Function: getExit
 ** Description:  Choose an exit.
 ** Parameters: An int choice.  If choice = 0 then user is prompted to
 **   make choice.
 ** Pre-Conditions: An object of a derived class of space must exist.
 ** Post-Conditions: A pointer to the selected space will be returned.
 *********************************************************************/
Space* Space::getExit(int numExit)
{
    char choice = ' ';
    std::cout << "You are in " << name << "." << std::endl;
    if (numExit == 0) // let user choose
    {
        for (int i=0; i<static_cast<int>(exits.size()); i++) {
            if (exits[i].open) { // show open exits
                std::cout << i+1 << ") " << exits[i].descr << std::endl;
            }
        }
        std::cout << "Where would you like to go? " << std::endl;
        while (numExit < 1 || numExit > static_cast<int>(exits.size())) {
            std::cout << "Enter a number: " <<std::endl;
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            numExit = static_cast<int>(choice) - static_cast<int>('0');
        }
    }
    std::cout << "You are going to " << exits[numExit-1].descr << std::endl;
    return exits[numExit-1].dest;
}

/*********************************************************************
 ** Function: openExit
 ** Description: Open an exit.
 ** Parameters: An int choice.
 ** Pre-Conditions: An exit object must exist.
 ** Post-Conditions: The open/closed state of the exit will be set to
 **   true (open).
 *********************************************************************/
void Space::openExit(int choice)
{
    if (choice > 0 && choice <= static_cast<int>(exits.size())) {
        exits[choice-1].open = true;
    }
}

/*********************************************************************
 ** Function: closeExit
 ** Description: Close an exit.
 ** Parameters: An int choice.
 ** Pre-Conditions: An exit object must exist.
 ** Post-Conditions: The open/closed state of the exit will be set to
 **   false (closed).
 *********************************************************************/
void Space::closeExit(int choice)
{
    if (choice > 0 && choice <= static_cast<int>(exits.size())) {
        exits[choice-1].open = false;
    }
}

/*********************************************************************
 ** Function: removeItems
 ** Description: Remove an item from the space items container.
 ** Parameters: None
 ** Pre-Conditions: An object of a derived class must exist.
 ** Post-Conditions: A string with the name of the removed item will
 **   be returned.
 *********************************************************************/
std::string Space::removeItems()
{
    return items->remove();
}

/*********************************************************************
 ** Function: addItems
 ** Description: Add an item from the space items container.
 ** Parameters: A string s.
 ** Pre-Conditions: An object of a derived class must exist.
 ** Post-Conditions: If the item is successfully added then true will
 **   be returned, false otherwise.
 *********************************************************************/
bool Space::addItems(std::string s)
{
    return items->add(s);
}

/*********************************************************************
 ** Function: lookItems
 ** Description: Look at the items in the container in a space.
 ** Parameters: None.
 ** Pre-Conditions: An object of the derived class must exist.
 ** Post-Conditions: The items in the items container will be printed
 **   to the screen.
 *********************************************************************/
void Space::lookItems()
{
    items->display();
}

Space::~Space()
{
    exits.empty();
    delete items;
}
