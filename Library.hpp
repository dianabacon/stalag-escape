/*********************************************************************
 ** Program Filename: Library.hpp
 ** Author: Diana Bacon
 ** Date: 2015-12-02
 ** Description: Implementation of the Library class.  Functions
 **   related to the derived class for Library spaces.
 *********************************************************************/

#ifndef Library_hpp
#define Library_hpp

#include <iostream>
#include "Space.hpp"

class Library : public Space
{
private:
    int proficiency;
    struct Phrase
    {
        std::string german;
        std::string english1;
        std::string english2;
        char correct;
        Phrase(std::string g, std::string e1, std::string e2, char c)
        {
            german = g;
            english1 = e1;
            english2 = e2;
            correct = c;
        }
    };
    std::vector<Phrase> phrases;

public:
    Library();
    bool enter(Airman* const);
    ~Library() {};
};

#endif /* Library_hpp */
