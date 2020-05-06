#pragma once

#include "Field.h"

/**
*Abstract game bonus class
*
*Any bonus should be inherited from this class. Has default constructor so coordinates must be set using special method SetPosition(). Has pure virtual function trigger(), rest of interface must be enough for anything
*
*To add a new bonus:
*1)Create new inherited class
*2)Create trigger() method
*3)Create new color_code in Main.h
*4)Make constructor which applies this new color_code, triggerMessage std::string and triggerColor sf::Color
5)In Main.h adjust BONUS_COUNT
6)Add it to bonus spawn in GameLoop
*/
class Bonus {
protected:
    color_code type;    /**Sets color_code for texture manager to find a proper texture*/
    unsigned x, y;  /**Coordinates in gemsMatrix*/
    std::string triggerMessage; /**Message shown when drawn*/
    sf::Color triggerColor; /**triggerMessage color*/
public:
    /**
    *Default constructor
    */
    Bonus() : x(0), y(0) {}

    /**
    *Default destuctor
    */
    ~Bonus() {}

    /**
    *Returns type of bonus as color_code
    */
    color_code GetType() { return type; }

    /**
    *Pure virtual function to activate bonus
    *
    *Should be overriden by each specific bonus. In most cases the only method you'll need to create except for constructor
    *
    *@param field Shared pointer to playfield Field object. Needed to interact with gemsMatrix
    */
    virtual void Trigger(std::shared_ptr<Field> field) = 0;

    /**
    *Set bonus x and y coordinates in gemsMatrix
    *
    *@param xnew New x coordinate in matrix
    *
    *@param ynew New y coordinate in matrix
    */
    void SetPosition(unsigned xnew, unsigned ynew);

    /**
    *Draw bonus tile in current coordinates using SFML means
    *
    *@param window Shared pointer to RenderWindow you want to draw in
    *
    *@param field Shared pointer to Field object you use in current game
    */
    void DrawBonus(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<Field> field);

    /**
    *Draw special message to make bonus more visible by SFML means
    *
    *Text and its color are specified for each bonus type in its constructor
    *
    *@param window Shared pointer to RenderWindow you want to draw in
    *
    *@param field Shared pointer to Field object you use in current game
    */
    void ShowTriggerText(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr <Field> field);
};