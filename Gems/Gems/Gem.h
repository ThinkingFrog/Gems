#pragma once
#include <SFML/Graphics.hpp>

//Main class for all objects on the game field
//Has sizes and color of each object
class Gem {
private:
    float width, height; //gem's individual sizes
    sf::Color color;    //gem's individual color decided from field's color spectre

public:
    Gem(float width, float height, sf::Color color);

    //Draw single gem in (x,y) coordinates
    void DrawGem(sf::RenderWindow *window, float x, float y);
};

