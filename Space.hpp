/*********************************************************************
 ** Program Filename: Space.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-27
 ** Description: Implementation of the Space class.  Functions and data
 **   related to the abstract base class for spaces.
 *********************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Container.hpp"

class Airman;

class Space
{
    
protected:
    std::string name;           // name of the space
    struct Exit                 // exit from a space
    {
        Space* dest;            // pointer to another space
        std::string descr;      // description of the path
        bool open;              // state open/closed of exit
        Exit( Space* d1, std::string d2, bool o = true)
        {
            dest = d1;
            descr = d2;
            open = o;
        }
    };
    std::vector<Exit> exits;    // all of the exits
    Container *items;           // a container of items
    
public:
    Space();
    virtual bool enter(Airman* const)=0;    // pure virtual function
    void setName(std::string);
    std::string getName();
    void setExit(Space*,std::string, bool = true);
    Space* getExit(int = 0);
    void openExit(int);
    void closeExit(int);
    std::string removeItems();
    bool addItems(std::string);
    void lookItems();
    virtual ~Space();
};

#endif /* Space_hpp */
