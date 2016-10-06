/*********************************************************************
 ** Program Filename: Forest.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-29
 ** Description: Implementation of the Forest class.  Functions
 **   related to the derived class for Forest spaces.
 *********************************************************************/

#ifndef Forest_hpp
#define Forest_hpp

#include <iostream>
#include "Space.hpp"

class Forest : public Space
{
private:

public:
    Forest();
    bool enter(Airman* const);
    ~Forest() {};
};

#endif /* Forest_hpp */
