#pragma once
#include <SFML/Graphics.hpp>

/**
*Global Font object used in bonus trigger message
*/
extern sf::Font font;

/**
*Loads font from Textures/defaultFont to glogal object
*
*Should only be called ones from Field constructor
*/
void InitFont();