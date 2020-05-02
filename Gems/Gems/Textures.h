#pragma once

#include "Main.h"

/**
*Special class used to load textures for entities
*
*Contains all textures in special <color_code, sf::Texture> dictionary using map
*
*Loads all textures on initialization through prewritten colorsSet map. Can return pointer to texture by color or directly by color_code and boolean if all textures could be loaded or not
*
*In order to upload new texture you should: 
*1)Create new color_code value in Main.h
*2)(optionally) Associate it with color in ColorType func
*3)Add pair of new color_code and texture name in colorsSet
*/
class TextureManager {
private:
    std::map <color_code, sf::Texture> texturesSet; /**Map dictionary containing preloaded textures associated with [color_code]s*/

    /**Map dictionary used to initialize textures by filename*/
    std::map <color_code, std::string> colorsSet = { {clGreen, "Green"}, {clBlue, "Blue"}, {clRed, "Red"}, {clYellow, "Yellow"},
        {clCyan, "Cyan"}, {clMagenta, "Magenta"}, {clBlack, "Black"}, {clBomb, "Bomb"}, {clPainter, "Painter"} };

public:
    /**
    *TextureManager class constructor
    *
    *Initializes texturesSet map with textures using colorsSet
    *
    *Also initializes font
    */
    TextureManager();

    /**
    *Default destructor
    */
    ~TextureManager() {}

    /**
    *Returns pointer to a texture associated with given color
    *
    *Mainly used to load textures for colored gems
    */
    sf::Texture* GetTextureByColor(sf::Color color);

    /**
    *Returns pointer to a texture directly by a color_code
    *
    *Mainly used to load textures for bonuses because they dont have a special color
    */
    sf::Texture* GetTextureByCode(color_code code);

    /**
    *Returns if all textures could be loaded or not
    *
    *Returns false if even one texture couldn't be loaded and disables all textures in game
    */
    bool TexturesSetIsDamaged();

    /**
    *Font object used in bonus trigger message
    */
    sf::Font font;
};