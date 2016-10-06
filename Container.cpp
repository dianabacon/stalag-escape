/*********************************************************************
 ** Program Filename: Container.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-30
 ** Description: Implementation of the Container class.  Functions
 **   describing the state and controlling the contents of containers.
 *********************************************************************/

#include "Container.hpp"

/*********************************************************************
 ** Function: Container
 ** Description: Default Constructor for the container class.
 ** Parameters:  String name and int limit.
 ** Pre-Conditions: None.
 ** Post-Conditions: A container object will be created.
 *********************************************************************/
Container::Container(std::string n, int l)
{
    name = n;
    limit = l;
}

/*********************************************************************
 ** Function: getLimit
 ** Description: Gets the value of the container size limit.
 ** Parameters: None.
 ** Pre-Conditions: A container object must exist.
 ** Post-Conditions: Returns maximum number of items that container
 **   can hold.
 *********************************************************************/
int Container::getLimit()
{
    return limit;
}

/*********************************************************************
 ** Function: setLimit
 ** Description: Sets the value of the container size limit.
 ** Parameters: An int l.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: The size limit of the container will be set.
 *********************************************************************/
void Container::setLimit(int l)
{
    limit = l;
}

/*********************************************************************
 ** Function: getName
 ** Description: Gets the value of the container name.
 ** Parameters: None.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: Returns a string containing the container name.
 *********************************************************************/
std::string Container::getName()
{
    return name;
}

/*********************************************************************
 ** Function: setName
 ** Description: Sets the value of the container name.
 ** Parameters: A string n.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: The name of the container will be set.
 *********************************************************************/
void Container::setName(std::string n)
{
    name = n;
}

/*********************************************************************
 ** Function: add
 ** Description: Adds an item to a container.
 ** Parameters:  A string s and a bool talk.
 ** Pre-Conditions: The values of the input parameters must be set.
 ** Post-Conditions: Will add an item to the container unless the
 **   item limit is exceeded or the item is already in the container.
 **   The informative text messages will not print if talk = false.
 *********************************************************************/
bool Container::add(std::string s, bool talk)

{
    if (inside(s))
    {
        if (talk) std::cout << "The " << s << " is already in " << "." << std::endl;
        return false;
    } else if (full()) {
        if (talk) std::cout << name <<" is full." << std::endl;
        if (talk) std::cout << "Couldn't add " << s << " to " << name << "." << std::endl;
        return false;
    } else {
        compartment.push_back(s);
        if (talk) std::cout << "Added " << s << " to " << name << "." << std::endl;
        return true;
    }
}

/*********************************************************************
 ** Function: remove
 ** Description: Removes a user-selected item from the container.
 ** Parameters: User input.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: A string containing the user-selected item to
 **   be removed will be returned, unless the user selects "Nothing"
 **   or the container is empty, in which case an empty string is
 **   returned.
 *********************************************************************/
std::string Container::remove()
{
    int n;
    if (compartment.empty()) {
        std::cout << name << " is empty.";
        return "";
    } else {
        display();
        std::cout << static_cast<int>(compartment.size())+1 << ") Nothing" << std::endl;
        std::cout << "Which item do you want to remove from the " << name << "? " << std::endl;
        std::cout << "Enter a number: ";
        std::cin >> n;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        if (n <= static_cast<int>(compartment.size())) {
            std::string s = compartment[n-1];
            compartment.erase(compartment.begin()+n-1);
            std::cout << "Removed " << s << " from " << name << "." << std::endl;
            return s;
        } else {
            return "";
        }
    }
}

/*********************************************************************
 ** Function: display
 ** Description: Displays a numbered list of all the items in the
 **   container.
 ** Parameters: None.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: A list of all the items in the container will be
 **   printed to the screen.
 *********************************************************************/
void Container::display()
{
    std::cout << "The " << name << " contains " << compartment.size()
    << " items:"  << std::endl;
    for (int i=0; i<static_cast<int>(compartment.size()); i++)
        std::cout << i+1 << ") " << compartment[i] << std::endl;
}

/*********************************************************************
 ** Function: full
 ** Description:  Checks to see if the container is full
 ** Parameters: None.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: Returns true if the container has reached the
 **   limit of items it can hold, false otherwise.
 *********************************************************************/
bool Container::full()
{
    if (limit > 0 && static_cast<int>(compartment.size()) >= limit)
    {
        return true;
    } else {
        return false;
    }
}

/*********************************************************************
 ** Function: empty
 ** Description: Checks to see if the container is empty.
 ** Parameters:
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions:
 *********************************************************************/
bool Container::empty()
{
    return compartment.empty();
}

/*********************************************************************
 ** Function: inside
 ** Description: Searches the list of items in the container to see if
 **   a particular item is inside.
 ** Parameters: A string s.
 ** Pre-Conditions:  A container object must exist.
 ** Post-Conditions: Returns true if one of the items in the compartment
 **   matches the input string.
 *********************************************************************/
bool Container::inside(std::string s)
{
    std::vector<std::string>::iterator it;
    it = find(compartment.begin(), compartment.end(), s);
    if (it != compartment.end())
    {
        return true;
    } else {
        return false;
    }
}

