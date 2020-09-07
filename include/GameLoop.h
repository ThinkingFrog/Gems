#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Bonus.h"
#include "Menu.h"

/**
*Game operating class
*
*Launches window loop that operates all graphics. All public interface is constructor and start() method
*
*Interface methods must not be edited, only inner modules if needed
*/
class GameLoop {
private:
    bool secondClick; /**Tracks if a gem is already selected and second click will be swapping or cancelling*/
    bool dropped;   /**Tracks if any gem was dropped by last FieldDrop() fucntion call*/
    bool bonusSpawned;  /**Tracks if any gem was spawned by last SpawnBonus() method call*/
    bool deleted;   /**Tracks if any combination of gems was deleted by last CheckFieldForMatching() function call*/
    bool bonusTriggered;    /**Tracks if a bonus was triggered in current frame*/
    bool hasFocus;   /**Tracks if current window is in background mode or not*/

    unsigned userResolutionWidth;   /**Window width*/
    unsigned userResolutionHeight;  /**Window height*/
    unsigned fieldWidth;    /**Amount of gems in one row*/
    unsigned fieldHeight;   /**Amount of gems in one column*/

    unsigned gem1X; /**First swapped gem x coordinate*/
    unsigned gem1Y; /**First swapped gem y coordinate*/
    unsigned gem2X; /**Second swapped gem x coordinate*/
    unsigned gem2Y; /**Second swapped gem y coordinate*/

    std::shared_ptr <sf::RenderWindow> window;  /**Smart pointer to a current RenderWindow entity*/
    std::shared_ptr <Field> field;  /**Smart pointer to a current Field class entity*/
    std::shared_ptr <Bonus> bonus;  /**Smart pointer to a universal Bonus class entity*/

    /**
    *Check occuring window events
    *
    *Currently proccesses closing of window and change of focus to other window and back
    *
    *Uses SFML means and sf::Event class specifically
    */
    void CheckEvents();

    /**
    *Trigger currently active bonus
    *
    *Call trigger() method for current bonus pointer and set proper booleans values
    */
    void TriggerBonus();

    /**
    *Call matching deletion, dropping and refilling and set boolens values
    *
    *Only calls deletion if last drop was unsuccessful and no bonus was triggered in current frame
    *
    *Calls drop anyway and sets boolean if it was successful or not
    *
    *Only calls refill if last drop was unsuccessful
    */
    void ProcessField();

    /**
    *Module that sets spawnX and spawnY to random coordinates in radius of 3 from first deleted gem
    *
    *@param spawnX Bonus x coordinate in matrix
    *
    *@param spawnY Bonus y coordinate in matrix
    */
    void SetRandomPoint(unsigned& spawnX, unsigned& spawnY);

    /**
    *Set bonus pointer to one of random bonus classes object
    */
    void SelectBonusType();

    /**
    *Spawn a random bonus
    *
    *Chance to spawn a bonus is 5 * [deleted gems]
    *
    *If previous condition passes randomly selects a bonus from given types
    *
    *Applies new bonus class to abstract Bonus class pointer, sets new random coordinates ans sets proper boolean
    */
    void SpawnBonus();

    /**
    *Module that implements selection of a gem with mouse
    *
    *Highlights chosen gem and makes program ready to choose a second one
    */
    void SelectFirstGem();

    /**
    *Module that implements selection of a second gem with mouse
    *
    *If gems are neighbouring, swaps them and removes highlight; if not, do nothing
    */
    void SelectSecondGem();

    /**
    *Cancel selection of the first gem
    *
    *Remove highlight and make program ready to choose first gem
    */
    void CancelSelection();

    /**
    *Controls all mouse interactions
    *
    *If no gem is selected, select gem under cursor
    *
    *If gem is already selected and left button is pressed, swap selected gem with the one under cursor
    *
    *If gem is already selected and right button is pressed, cancel selection
    */
    void MouseControls();
public:
    /**
    *Default class constructor
    */
    GameLoop();

    /**
    *Default class destructor
    */
    ~GameLoop() {
        bonus.reset();
    }

    /**
    *Begin game loop
    */
    void Start(Menu menu);
};