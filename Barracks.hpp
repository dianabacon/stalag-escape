/*********************************************************************
 ** Program Filename: Barracks.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Definition of the Barracks class.  Functions and data
 **   related to the derived class for Barracks spaces.
 *********************************************************************/

#ifndef Barracks_hpp
#define Barracks_hpp

#include <iostream>
#include "Space.hpp"

class Barracks : public Space
{
private:
    bool lightOn;   // lights are on
public:
    Barracks();                 // default constructor
    bool enter(Airman* const);  // special function
    ~Barracks() {};             // destructor
};

#endif /* Barracks_hpp */
