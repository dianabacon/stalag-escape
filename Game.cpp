/*********************************************************************
 ** Program Filename: Game.hpp
 ** Author: Diana Bacon
 ** Date: 2015-12-02
 ** Description: Implementation of the Game class.  High level
 **   control of Stalag Escape game, including unit tests.
 *********************************************************************/

#include "Game.hpp"

/*********************************************************************
 ** Function:  Game
 ** Description: Constructor for the Game class.
 ** Parameters: none.
 ** Pre-Conditions: none.
 ** Post-Conditions: The game spaces, exits and character will be
 **   created and defined.
 *********************************************************************/
Game::Game()
{
    // create spaces
    barracks = new Barracks;
    forest = new Forest;
    library = new Library;
    canteen = new Canteen;
    playfield = new PlayField;
    tunnel = new Tunnel;
    
    // create the barracks
    barracks->setName("Barracks #1");
    barracks->setExit(barracks, "stay in the barracks.");
    barracks->setExit(forest,"climb over the perimeter fence.");
    barracks->setExit(library, "go to the library.");
    barracks->setExit(canteen, "go to the canteen.");
    barracks->setExit(playfield, "go to the playing field.");
    
    // create the forest
    forest->setName("the forest");
    forest->setExit(barracks, "Captured, return to barracks.");
    forest->setExit(library, "Captured, return to the library.");
    forest->setExit(canteen, "Captured, return to canteen.");
    forest->setExit(tunnel, "change mind, return to tunnel.");
    
    // create the library
    library->setName("the library");
    library->setExit(barracks, "go to the barracks.");
    library->setExit(forest, "stow away in a delivery truck.");
    library->setExit(library, "stay in the library.");
    library->setExit(canteen, "go to the canteen.");
    library->setExit(playfield, "go to the playing field.");
    
    // create the canteen
    canteen->setName("the canteen");
    canteen->setExit(barracks, "go to the barracks.");
    canteen->setExit(forest, "sneak through the front gate.");
    canteen->setExit(library, "go to the library.");
    canteen->setExit(canteen, "stay in the canteen.");
    canteen->setExit(playfield, "go to the playing field.");
    
    // create the playfield
    playfield->setName("the playing field");
    playfield->setExit(barracks, "go to the barracks.");
    playfield->setExit(library, "go to the library.");
    playfield->setExit(canteen, "go to the canteen.");
    playfield->setExit(playfield, "stay on the playing field.");
    // tunnel exit is closed unless covered by wooden horse
    playfield->setExit(tunnel, "enter secret tunnel.", false);
    
    // create the tunnel
    tunnel->setName("the tunnel");
    tunnel->setExit(tunnel, "stay in the tunnel.");
    tunnel->setExit(playfield, "climb out onto playing field.");
    //  forest exit is closed until player helps dig out the tunnel
    tunnel->setExit(forest, "climb out into the forest.", false);
    
    // set the character's initial location
    airman = new Airman;
    airman->setLocation(barracks);
}

/*********************************************************************
 ** Function: displayTheme
 ** Description: Displays the theme of the game.
 ** Parameters: None.
 ** Pre-Conditions: A game object must have been created.
 ** Post-Conditions: The theme will be printed to the screen.
 *********************************************************************/
void Game::displayTheme()
{
    std::cout << "################### STALAG ESCAPE ########################" << std::endl;
    std::cout << "    During WWII, you are a British airman, felled over    " << std:: endl;
    std::cout << "  enemy airspace, and held as a prisoner of war behind    " << std:: endl;
    std::cout << " enemy lines at a German Stalag (POW camp). As you move   " << std:: endl;
    std::cout << " through the camp, you collect items to help you escape,  " << std:: endl;
    std::cout << " learn a few German phrases, and find different potential " << std:: endl;
    std::cout << " escape routes, but there is only one way to succeed.  If " << std:: endl;
    std::cout << " you take the wrong escape route or are ill-prepared, you " << std:: endl;
    std::cout << "will be captured and the game is over. You have a rucksack" << std:: endl;
    std::cout << " that can hold 4 items. You start the game with a pack of " << std:: endl;
    std::cout << " cigarettes in your rucksack.  You have 24 hours to escape" << std:: endl;
    std::cout << " before the Soviet Army arrives to “liberate” you and send" << std:: endl;
    std::cout << "     you on a forced wintertime march to another camp.    " << std:: endl;
    std::cout << "##########################################################" << std::endl;
    std::cout << std::endl;
}

/*********************************************************************
 ** Function: displayMap
 ** Description: Prints a map of the game world to the screen.  
 ** Parameters: None.
 ** Pre-Conditions: A game object must have been created.
 ** Post-Conditions: A map of the game world will be printed to the 
 **   screen.
 *********************************************************************/
void Game::displayMap()
{
    std::cout << "                                                        " << std::endl;
    std::cout << "                      STALAG MAP                        " << std::endl;
    std::cout << "                                                        " << std::endl;
    std::cout << " ###################################################### " << std::endl;
    std::cout << " #                                   Perimeter Fence  # " << std::endl;
    std::cout << " #     --------------          -----------            # " << std::endl;
    std::cout << " #     |             |         |          |           # " << std::endl;
    std::cout << " #     | Barracks    |         | Canteen  |           # " << std::endl;
    std::cout << " #     |             |         |          |           # " << std::endl;
    std::cout << " #      -------------          -----------            # " << std::endl;
    std::cout << " #                                                    # " << std::endl;
    std::cout << " #     -----------             -----------            # " << std::endl;
    std::cout << " #     |          |            |          |           # " << std::endl;
    std::cout << " #     | Library  |            | Playing  |           # " << std::endl;
    std::cout << " #     |          |            |  Field   |           # " << std::endl;
    std::cout << " #      -----------            |          |           # " << std::endl;
    std::cout << " #                              ----------            # " << std::endl;
    std::cout << " ###################################################### " << std::endl;
    std::cout << "      *      *           *       *      *    *   *      " << std::endl;
    std::cout << "        *         *   Forest   *    *      *       *    " << std::endl;
    std::cout << "                                                        " << std::endl;
}

/*********************************************************************
 ** Function: displaySolution
 ** Description: Displays the solution to the game.
 ** Parameters:  None.
 ** Pre-Conditions: A game object must have been created.
 ** Post-Conditions: The solution to the game will be printed to the 
 **   screen.
 *********************************************************************/
void Game::displaySolution()
{
    std::cout << std::endl;
    std::cout << "In order to escape, you need to have" << std::endl;
    std::cout << "these items in your rucksack:" << std::endl;
    std::cout << "1) a silk map" << std::endl;
    std::cout << "2) German Reichsmarks" << std::endl;
    std::cout << "3) Compass" << std::endl;
    std::cout << "4) Forged Identification" << std::endl;
    std::cout << "and you must enter the forest via the secret tunnel.";
    std::cout << std::endl << std::endl;
}

/*********************************************************************
 ** Function: play
 ** Description: Play the game.
 ** Parameters:  Text based input for user choice of items to pick
 **   up or put down and which exit to take, as well as interactions
 **   with each space's special function.
 ** Pre-Conditions: A game object must have been created with pointers
 **   between spaces defined and items.  Each space in the Game class
 **   must have a special function named "enter" defined.
 ** Post-Conditions: Text based output describing the progress of
 **   the airman character through the spaces in the stalag.  Items
 **   in each space and in the airman's rucksack will be periodically
 **   displayed. Text based menus for the user to choose items and exits
 **   will be displayed.
 *********************************************************************/
void Game::play()
{
    bool escaped = false;
    std::string item = "";
    int time = 0;
    
    // start timer
    while (!escaped && time < 24) {
        
        time++;
        std::cout << "The time is " << time << ":00." << std::endl;
        
        // see if he has escaped
        if (airman->getLocation() == forest) {
            forest->closeExit(1);
            forest->closeExit(2);
            forest->closeExit(3);
            forest->closeExit(4);
            
            if (airman->lastLocation() == tunnel) {
                // came through correct path
                if (airman->getLocation()->enter(airman)) {
                    // has all required items
                    std::cout << "You have escaped :-)" << std::endl;
                    escaped = true;
                } else {
                    // does not have required items
                    std::cout << "Go back and try again. :-|" << std::endl;
                    forest->openExit(4);
                }
            } else {
                // did not come through correct path
                std::cout << "You have been captured :-(" << std::endl;
                if (airman->lastLocation() == barracks) {
                    forest->openExit(1);
                } else if (airman->lastLocation() == library) {
                    forest->openExit(2);
                } else if (airman->lastLocation() == canteen) {
                    forest->openExit(3);
                }
            }
        
            if (!escaped) { // keep going
                airman->move();
          }

        } else { // not in forest
            if (airman->getLocation()->enter(airman)) {
                airman->lookAround();
                airman->lookRucksack();
                airman->decide();
            }
            airman->move();
        }
        
    } // end while
    
    if (!escaped) std::cout << "Time up!  Game over :-(" << std::endl;
}

/*********************************************************************
 ** Function: ~Game
 ** Description: Destructor for the game class.
 ** Parameters: None.
 ** Pre-Conditions: A game object must have been created.
 ** Post-Conditions: Dynamically allocated objects are destroyed.
 *********************************************************************/
Game::~Game()
{
    delete barracks;
    delete forest;
    delete library;
    delete canteen;
    delete playfield;
    delete tunnel;
    delete airman;
}

/*********************************************************************
 ** Function: test_rucksack
 ** Description: Automated test adding, removing and finding items in 
 **   rucksack.
 ** Parameters: None.
 ** Pre-Conditions:  The airman object must exist and have a container
 **   object named rucksack.
 ** Post-Conditions: Output verifying correct operation of the container
 **   object will be printed to the screen.
 *********************************************************************/
void Game::test_rucksack()
{
    airman->addRucksack("silk map");
    airman->addRucksack("compass");
    airman->removeRucksack();
    airman->addRucksack("German Reichsmarks");
    airman->addRucksack("Forged Identification");
    airman->lookRucksack();
    if (airman->inRucksack("silk map") &&
        airman->inRucksack("German Reichsmarks") &&
        airman->inRucksack("compass") &&
        airman->inRucksack("Forged Identification")) {
        std::cout << "items are in the rucksack"  << std::endl;
    } else {
        std::cout << "the items are not in the rucksack" << std::endl;
    }
}

/*********************************************************************
 ** Function: test_pointers
 ** Description: Automated test to verify correct operation of all
 **   pointers between Space objects in game.
 ** Parameters: None.
 ** Pre-Conditions: A game object must have been created with specific
 **   pointers between spaces defined.
 ** Post-Conditions: Output verifying correct performance of the
 **   pointers between spaces (exits) will be printed to the screen.
 *********************************************************************/
void Game::test_pointers()
{
    // open hidden exits
    forest->openExit(4);
    playfield->openExit(5);
    tunnel->openExit(3);
    
    // to and from the barracks
    airman->setLocation(barracks);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(1));
    std::cout << std::endl;
    
    // to and from the canteen
    airman->setLocation(canteen);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(4));
    std::cout << std::endl;
    
    // to and from the forest
    airman->setLocation(forest);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(3));
    std::cout << std::endl;
    
    // to and from the library
    airman->setLocation(library);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(3));
    std::cout << std::endl;
    
    // to and from the playing field
    airman->setLocation(playfield);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(4));
    airman->setLocation(airman->getLocation()->getExit(5));
    airman->setLocation(airman->getLocation()->getExit(5));
    std::cout << std::endl;
    
    
    // to and from the tunnel
    airman->setLocation(tunnel);
    airman->setLocation(airman->getLocation()->getExit(1));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(2));
    airman->setLocation(airman->getLocation()->getExit(3));
    airman->setLocation(airman->getLocation()->getExit(4));
    std::cout << std::endl;
    
}

/*********************************************************************
 ** Function: test navigation
 ** Description: Interactive test to verify player is able to move
 **   from space to space.
 ** Parameters:  Text based input for user choice of which exit to take.
 ** Pre-Conditions: A game object must have been created with pointers
 **   between spaces defined. An airman object must have been created.
 ** Post-Conditions: Text based output describing the progress of the
 **   airman character through the spaces in the stalag. Text based
 **   menus for the user to choose exits will be displayed.
 *********************************************************************/
void Game::test_navigation()
{
    // open hidden exits
    forest->openExit(4);
    playfield->openExit(5);
    tunnel->openExit(3);
    
    int time = 0;
    // time loop
    while (time < 24) {
        time++;
        airman->move();
    }
}

/*********************************************************************
 ** Function: test navigation
 ** Description: Interactive test to verify player is able to move
 **   from space to space and pick up and put down items.
 ** Parameters:  Text based input for user choice of items to pick
 **   up or put down and which exit to take.
 ** Pre-Conditions: A game object must have been created with pointers
 **   between spaces defined and items.
 ** Post-Conditions: Text based output describing the progress of
 **   the airman character through the spaces in the stalag.  Items
 **   in each space and in the airman's rucksack will be periodically
 **   displayed. Text based menus for the user to choose items and exits
 **   will be displayed.
 *********************************************************************/
void Game::test_items()
{
    
    // open hidden exits
    forest->openExit(4);
    playfield->openExit(5);
    tunnel->openExit(3);
    
    int time = 0;
    // time loop
    while (time < 24) {
        time++;
        airman->lookAround();
        airman->lookRucksack();
        airman->decide();
        airman->move();
    }
}

/*********************************************************************
 ** Function: test actions
 ** Description: Interactive test to verify player is able to move
 **   from space to space and pick up and put down items and interact
 **   with each space's special function.
 ** Parameters:  Text based input for user choice of items to pick
 **   up or put down and which exit to take, as well as interactions
 **   with each space's special function.
 ** Pre-Conditions: A game object must have been created with pointers
 **   between spaces defined and items.  Each space in the Game class
 **   must have a special function named "enter" defined.
 ** Post-Conditions: Text based output describing the progress of
 **   the airman character through the spaces in the stalag.  Items
 **   in each space and in the airman's rucksack will be periodically
 **   displayed. Text based menus for the user to choose items and exits
 **   will be displayed.
 *********************************************************************/
void Game::test_actions()
{
    
    int time = 0;
    // time loop
    while (time < 24) {
        time++;
        if (airman->getLocation()->enter(airman)) {
            airman->lookAround();
            airman->lookRucksack();
            airman->decide();
        }
        airman->move();
    }
}
