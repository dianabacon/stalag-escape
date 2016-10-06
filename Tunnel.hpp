/*********************************************************************
 ** Program Filename: Tunnel.cpp
 ** Author: Diana Bacon
 ** Date: 2015-11-29
 ** Description: Definition of the Tunnel class.  Functions and data
 **   related to the derived class for Tunnel spaces.
 *********************************************************************/

#ifndef Tunnel_hpp
#define Tunnel_hpp

#include <iostream>
#include <string>
#include "Space.hpp"

class Tunnel : public Space
{
private:
    int dirt;                   // dirt blocking the tunnel
public:
    Tunnel();                   // constructor
    bool enter(Airman* const);  // special function
    ~Tunnel() {};               // destructor
};

#endif /* Tunnel_hpp */
