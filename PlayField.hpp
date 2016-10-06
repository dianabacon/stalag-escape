/*********************************************************************
 ** Program Filename: PlayField.hpp
 ** Author: Diana Bacon
 ** Date: 2015-11-28
 ** Description: Definition of the PlayField class.  Functions and data
 **   related to the derived class for PlayField spaces.
 *********************************************************************/

#ifndef PlayField_hpp
#define PlayField_hpp

#include <iostream>
#include <vector>
#include "Space.hpp"

class PlayField : public Space
{
private:

public:
    PlayField();                // constructor
    bool enter(Airman* const);  // special function
    ~PlayField() {};            // destructor
};

#endif /* PlayField_hpp */
