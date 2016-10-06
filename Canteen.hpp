/*********************************************************************
 ** Program Filename: Canteen.cpp
 ** Author: Diana Bacon
 ** Date: 2015-12-05
 ** Description: Definition of the Canteen class.  Functions and data
 **   related to the derived class for Canteen spaces.
 *********************************************************************/

#ifndef Canteen_hpp
#define Canteen_hpp

#include <iostream>
#include "Space.hpp"

class Canteen : public Space
{
private:
    
public:
    Canteen();                  // default constructor
    bool enter(Airman* const);  // special function
    ~Canteen() {};              // destructor
};

#endif /* Canteen_hpp */
