#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Textures.h"

/**
*Essential field cell class
*
*This class is used to store all information about typical member of playfield. It contains size of a cell (same for all) and unique gem color and outline color.
*Can manipulate cell's color to set it to any value or specifically set is empty (Black). Also can draw cell through SFML means using DrawGem() method
*
*/
class Gem {
private:

    float width, height;    /**Common size of any cell*/
    sf::Color color;    /**Individual gem color */
    sf::Color outline;  /**Individual gem's outline color */

public:
    /**
    *Gem constructor
    *
    *Creates a gem member with given sizes and color
    *
    *Should only be used in field generation and nowhere outside of it, because no new cells should be generated anywhere else
    *
    */
    Gem(float width, float height, sf::Color color);

    /**
    *Default destructor
    */
    ~Gem() {}

    /**
    *Return color of specific gem
    */
    sf::Color GetColor();

    /**
    *Set gem's color to black
    *
    *Used to mark gem as an empty space so it becomes unable to interact with other gems and should be filled with any other color by dropping or refilling
    */
    void SetEmpty();

    /**
    *Set gem's color to any value
    */
    void SetColor(sf::Color newColor);

    /**
    *Set gem's outline color to any value
    *
    *Mainly used to highlight gem with yellow or return it back to black
    */
    void SetOutlineColor(sf::Color newOutline);

    /**
    *Return if gem is empty or not
    *
    *If gem's color is black returns true, else returns false
    */
    bool IsEmpty();

    /**
    *Draw gem in specific place
    *
    *@param window Shared pointer to SFML RenderWindow object you want to draw in
    *
    *@param texMng Texture manager specified by current Field object, should be written as field->texMng
    *
    *@param x Window x coordinate of upper-left point
    *
    *@param y Window y coordinate of upper-left point
    */
    void DrawGem(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<TextureManager> texMng, float x, float y);
};