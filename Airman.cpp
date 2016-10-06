/*********************************************************************
 ** Program Filename: Airman.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Implementation of the Airman class.  Functions
 **   controlling actions of the airman character in the game.
 *********************************************************************/

#include "Airman.hpp"

/*********************************************************************
 ** Function: Airman
 ** Description: Constructor of the Airman class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: An Airman object will be created.
 *********************************************************************/
Airman::Airman()
{
    rucksack = new Container("rucksack",4);
    rucksack->add("cigarettes", false);}

/*********************************************************************
 ** Function: getLocation
 ** Description:  Gives current location.
 ** Parameters: None.
 ** Pre-Conditions: An airman object must exist.
 ** Post-Conditions: A pointer to the current Space will be returned.
 *********************************************************************/
Space* Airman::getLocation()
{
    return location;
}

/*********************************************************************
 ** Function: lastLocation
 ** Description:  Gives previous location.
 ** Parameters: None.
 ** Pre-Conditions: An airman object must exist.
 ** Post-Conditions: A pointer to the previous Space will be returned.
 *********************************************************************/
Space* Airman::lastLocation()
{
    return last;
}

/*********************************************************************
 ** Function: setLocation
 ** Description: Set a new location for the airman object.
 ** Parameters: A pointer to an existing space object.
 ** Pre-Conditions:  The airman object and space object must exist.
 ** Post-Conditions:  The current location and last location pointers
 **   for this airman object will be updated.
 *********************************************************************/
void Airman::setLocation(Space* l)
{
    last = location;
    location = l;
}

/*********************************************************************
 ** Function: removeRucksack
 ** Description: Remove an item from the rucksack.
 ** Parameters: None.
 ** Pre-Conditions: A rucksack container must exist.
 ** Post-Conditions:  An item will be removed from the rucksack.  A 
 ** string with the name of the item removed will be returned.
 *********************************************************************/
std::string Airman::removeRucksack()
{
    return rucksack->remove();
}

/*********************************************************************
 ** Function: addRucksack
 ** Description: Add an item to the rucksack.
 ** Parameters: A string containing the name of the item added.
 ** Pre-Conditions: A rucksack container must exist.
 ** Post-Conditions: An item will be added to the rucksack.
 *********************************************************************/
bool Airman::addRucksack(std::string s)
{
    return rucksack->add(s);
}

/*********************************************************************
 ** Function: inRucksack
 ** Description: Determines if an item is in the rucksack.
 ** Parameters: A string with the name of the item.
 ** Pre-Conditions: A rucksack container must exist.
 ** Post-Conditions: If the item is in the rucksack, true will be 
 **   returned, otherwise false will be returned.
 *********************************************************************/
bool Airman::inRucksack(std::string s)
{
    return rucksack->inside(s);
}

/*********************************************************************
 ** Function: lookRucksack
 ** Description: Display the contents of the rucksack for the user.
 ** Parameters: None.
 ** Pre-Conditions: A rucksack container must exist.
 ** Post-Conditions: The contents of the rucksack will be displayed.
 *********************************************************************/
void Airman::lookRucksack()
{
    rucksack->display();
}

/*********************************************************************
 ** Function: lookAround
 ** Description: Display the contents of the curent space's container.
 ** Parameters: None.
 ** Pre-Conditions: A rucksack container must exist.  The current space
 **   must have a container named items.
 ** Post-Conditions: The items in the current space will be displayed.
 *********************************************************************/
void Airman::lookAround()
{
    getLocation()->lookItems();
}

/*********************************************************************
 ** Function: move
 ** Description:  Allow the airman to move based on user choice.
 ** Parameters:  User selection of exits.
 ** Pre-Conditions:  The airman object must exist.  The current location
 **   must have exits defined.
 ** Post-Conditions:  The location of the airman will be changed.
 *********************************************************************/
void Airman::move()
{
    setLocation(getLocation()->getExit());
}

/*********************************************************************
 ** Function: decide
 ** Description: The user will decide what items the airman will pick
 **   up or put down.
 ** Parameters: User selection of whether to pick up an item and put
 **   it in his rucksack, take an item out of his rucksack and put it
 **   down in the space, or swap two items between the rucksack and the
 **   current space.
 ** Pre-Conditions: The airman object must exist.  The current location
 **   must have an items container. The airman must have a rucksack
 **   container.
 ** Post-Conditions:  Items may be moved between the airman's rucksack
 **   and the items container of the current location, depending on
 **   user selection.
 *********************************************************************/
void Airman::decide()
{
    char choice;
    std::cout << std::endl;
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "u) pick up an item" << std::endl;
    std::cout << "d) put down an item" << std::endl;
    std::cout << "s) swap two items" << std::endl;
    std::cout << "m) move on" << std::endl;
    std::cout << "Enter u, d, s, or m: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    switch (choice) {
        case 'u':
            pickUp();
            break;
        case 'd':
            putDown();
            break;
        case 's':
            putDown();
            pickUp();
            break;
            
        default:
            std::cout << "Moving on." << std::endl;
            break;
    } 
}

/*********************************************************************
 ** Function: pickUp
 ** Description: Remove an item from the current space and place it in
 **   the rucksack, if there is room.
 ** Parameters:  User selection of item to pick up.
 ** Pre-Conditions: The airman object must exist.  The current location
 **   must have an items container. The airman must have a rucksack
 **   container.
 ** Post-Conditions:  Items may be added to the airman's rucksack
 **   and removed from the items container of the current location,
 **   depending on user selection.
 *********************************************************************/
void Airman::pickUp()
{
    bool added = true;
    std::string item;
    item = getLocation()->removeItems();
    added = true;
    if (item != "") {
        added = addRucksack(item);
    }
    if (!added) {
        removeRucksack();
        addRucksack(item);
    }
}

/*********************************************************************
 ** Function: putDown
 ** Description: Remove an item from the rucksack and place it in
 **   the items container of the current space.
 ** Parameters:  User selection of item to put down.
 ** Pre-Conditions: The airman object must exist.  The current location
 **   must have an items container. The airman must have a rucksack
 **   container.
 ** Post-Conditions:  Items may be added to items container of the
 **   current location and removed from the the airman's rucksack,
 **   depending on user selection.
 *********************************************************************/
void Airman::putDown()
{
    std::string item;
    item = removeRucksack();
    if (item != "")
        getLocation()->addItems(item);
}

/*********************************************************************
 ** Function: ~Airman
 ** Description: Destructor for the Airman class.
 ** Parameters: None.
 ** Pre-Conditions: An airman object must exist.
 ** Post-Conditions: Dynamically allocated objects will be deleted.
 *********************************************************************/
Airman::~Airman()
{
    delete rucksack;
}
