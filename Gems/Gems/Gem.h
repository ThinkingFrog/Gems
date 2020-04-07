#pragma once
#include <SFML/Graphics.hpp>

//Main class for all objects on the game field
//Has sizes and color of each object
class Gem {
private:
    unsigned width, height; //gem's individual sizes
    sf::Color color;    //gem's individual color decided from field's color spectre

public:
    Gem(unsigned width, unsigned height, sf::Color color);
};

