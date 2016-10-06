/*********************************************************************
 ** Program Filename: Container.hpp
 ** Author: Diana Bacon
 ** Date: 2015-11-30
 ** Description: Definition of the Container class.  Functions and data
 **   describing the state and controlling the contents of containers.
 *********************************************************************/

#ifndef Container_hpp
#define Container_hpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Container
{
private:
    int limit;                              // maximum number of items
    std::vector<std::string> compartment;   // container for items
    std::string name;                       // container name displayed to user
    
public:
    Container(std::string = "container", int = -1);
    int getLimit();
    void setLimit(int);
    std::string getName();
    void setName(std::string);
    bool add(std::string, bool = true);
    std::string remove();
    void display();
    bool full();
    bool empty();
    bool inside(std::string);
};

#endif /* Container_hpp */
