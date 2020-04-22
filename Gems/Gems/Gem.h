#pragma once
#include <SFML/Graphics.hpp>

//Main class for all objects on the game field
//Has sizes and color of each object
class Gem {
private:

    float width, height; //gem's individual sizes
    sf::Color color;    //gem's individual color decided from field's color spectre
    sf::Color outline;
    sf::Texture texture;

public:
    Gem(float width, float height, sf::Color color, std::string newTexture);

    sf::Color GetColor(void);

    void SetEmpty(void);

    void SetColor(sf::Color newColor);

    //function mainly used to highlight gem with yellow
    void SetOutlineColor(sf::Color newOutline);

    bool IsEmpty(void);

    //Draw single gem in (x,y) coordinates
    void DrawGem(sf::RenderWindow* window, float x, float y);
};