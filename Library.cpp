/*********************************************************************
 ** Program Filename: Library.cpp
 ** Author: Diana Bacon
 ** Date: 2015-12-02
 ** Description: Implementation of the Library class.  Functions
 **   related to the derived class for Library spaces.
 *********************************************************************/

#include "Library.hpp"

/*********************************************************************
 ** Function: Library
 ** Description: Default constructor for the Library class.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: A Library object will be created. The items
 **   container is given a name and some items are added.
 *********************************************************************/
Library::Library()
{
    items->setName("Bookshelf");
    items->add("Forged Identification", false);
    items->add("Life Magazine", false);
    items->add("Murder in the Submarine Zone (novel)", false);
    
    proficiency = 0;
    
    phrases.push_back(Phrase("Wo ist der Bahnhof?",
                                  "Where is the train station?",
                                  "Where is the bathroom?",
                                  'a'));
    
    phrases.push_back(Phrase("Ich besorge das Bier.",
                                  "I believe that's correct.",
                                  "I'll get the beer.",
                                  'b'));
    
    phrases.push_back(Phrase("Ein Ticket nach Danzig, bitte.",
                                  "A ticket to go dancing, please.",
                                  "One ticket to Danzig, please.",
                                  'b'));
    
    phrases.push_back(Phrase("Ich bin ein norwegischer Margarine Verkäufer",
                                  "I am a Norwegian margarine salesman.",
                                  "Margarine normally makes me cough.",
                                  'a'));

}

/*********************************************************************
 ** Function: enter
 ** Description: Controls entry into a Library space.
 ** Parameters: A pointer to an Airman object.
 ** Pre-Conditions: A Library object must exist.
 ** Post-Conditions:  If you learn 4 German phrases you gain access
 **   to the bookshelf items.
 *********************************************************************/
bool Library::enter(Airman *myAirman)
{
    std::cout << "You are in " << getName() << std::endl;
    char choice = ' ';
    std::cout << "The escape committe wants you to learn a few German phrases." << std::endl;
    std::cout << "You are " << proficiency*25 << "% proficient in German" << std::endl;
    if (proficiency < 4) {
        std::cout << "Here is a German phrase:" << std::endl;
        std::cout << phrases[proficiency].german << std::endl;
        std::cout << "a) " << phrases[proficiency].english1 << std::endl;
        std::cout << "b) " << phrases[proficiency].english2 << std::endl;
        std::cout << "Which is the correct translation? (a or b): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        if (choice == phrases[proficiency].correct) {
            proficiency++;
            std::cout << "That is correct." << std::endl;
        } else {
            std::cout << "That is not correct." << std::endl;
        }
        return false;
    } else {
        return true;
    }
}