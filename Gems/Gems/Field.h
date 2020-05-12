#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "Gem.h"
#include "Textures.h"

/**
*Essential game class
*
*Allows gems storage in matrix and operations with them
*
*Keeps all information about settings
*/
class Field {
private:
    std::vector <std::vector <Gem>> gemsMatrix; /**Matrix of all gem objects on the screen*/
    const std::array <sf::Color, 6> colorsSpectre = { sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta };    /**Array of all possible colors*/
    float width, height; /**Size of field taken from current window's size*/
    unsigned gemsInRow, gemsInColumn;   /**Amount of gems on the playfield*/
    std::vector <std::array <unsigned, 2>> matching; /**Vector of matching gems, refreshed each time for a new combination*/
public:
    std::shared_ptr <TextureManager> texMng;    /**Smart pointer to a texture manager*/

    /**
    *Field class contructor
    *
    *@param windowWidth Width of sf::RenderWindow object
    *
    *@param windowHeight Height of sf::RenderWindow object
    *
    *@param gemsInRow Width of field in gems
    *
    *@param gemsInRow Width of field in gems
    */
    Field(float windowWidth, float windowHeight, unsigned gemsInRow, unsigned gemsInColumn);

    /**
    *Default destructor
    */
    ~Field() {}

    /**
    *Generate new field
    *
    *initialize gemsMatrix with gems of random numbers
    */
    void GenerateField(void);

    /**
    *Return array of all available colors for gems
    */
    std::array<sf::Color, 6> GetColorsSpectre(void);

    /**
    *Return field width in gems as unsigned
    */
    unsigned GetGemsInRow();

    /**
    *Return field height in gems as unsigned
    */
    unsigned GetGemsInColumn();

    /**
    *Return vector of matching gems
    *
    *Returns vector filled after checking for combinations on the field
    */
    std::vector<std::array<unsigned, 2>> GetMatchingVector();

    /**
    *Draw all field
    *
    *Goes through gemsmatrix and calls DrawGem() for each object
    *
    *@param window Smart pointer to sf::RenderWindow object in which you wish to draw
    */
    void DrawField(std::shared_ptr <sf::RenderWindow> window);

    /**
    *Check all upper and one left neighbours of a gem
    *
    *Mainly must be used while generating field to make it less random
    *
    *@param i X coordinate of a gem in matrix
    *
    *@param j Y coordinate of a gem in matrix
    *
    *@param tmp Current row vector in matrix
    */
    unsigned CheckNeighboursColors(unsigned i, unsigned j, std::vector <Gem> tmp);

    /**
    *Paints all gems from vector into color of original gem
    *
    *@param painted Vector containing gems coordinates that need to be painted
    *
    *@param x X coordinate of a gem with original color
    *
    *@param y Y coordinate of a gem with original color
    */
    void SetNewColors(std::vector<std::array<unsigned, 2>> painted, unsigned x, unsigned y);

    /**
    *Find and delete any combination of 3+ matching gems
    *
    *Returns a boolean if any combination was deleted or not
    */
    bool CheckFieldForMatching();

    /**
    *Delete gems from vector
    *
    *Recieves a vector of gem coordinates and sets them as empty
    *
    *@param matching Vector of gems coordinates that need to be set empty
    */
    void FieldDeletion(std::vector <std::array <unsigned, 2>> matching);

    /**
    *Check if given coordinates already exist in matching vector field
    *
    *@param i X coordinate that needs to be checked
    *
    *@param j Y coordinate that needs to be checked
    */
    bool AlreadyMatched(unsigned i, unsigned j);

    /**
    *Recursive function to check matching neighbours
    *
    *Recursively goes through neighbours (up, down, left, right) and adds them in matching vector field
    *
    *@param i X coordinate that needs to be checked
    *
    *@param j Y coordinate that needs to be checked
    */
    void CheckMatch(unsigned i, unsigned j);

    /**
    *Drops all available gems
    *
    *Goes through gemsMatrix and if possible changes each gem with an empty cell below
    */
    bool FieldDrop();

    /**
    *Refills all empty cells at once
    *
    *Goes through gemsMatrix and sets random color to a cell if it's empty
    */
    void FieldRefill();

    /**
    *Sets gem highlighted
    *
    *Sets outline color of a gem with given coordinates to yellow
    *
    *@param x X coordinate of a gem
    *
    *@param y Y coordinate of a gem
    */
    void SetHighlighted(unsigned x, unsigned y);

    /**
    *Removes gem's highlight
    *
    *Sets outline color of a gem with given coordinates to yellow
    *
    *@param x X coordinate of a gem
    *
    *@param y Y coordinate of a gem
    */
    void RemoveHighlight(unsigned x, unsigned y);

    /**
    *Swap two gems
    *
    *Exchange colors of gems with given coordinates
    *
    *@param x1 X coordinate of a first gem
    *
    *@param y1 Y coordinate of a first gem
    *
    *@param x2 X coordinate of a second gem
    *
    *@param y2 Y coordinate of a second gem
    */
    void Swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
};