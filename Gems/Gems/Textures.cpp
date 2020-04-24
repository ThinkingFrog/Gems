#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Textures.h"

std::vector <sf::Texture> texturesSet;

void InitTexturesSet(void) {
    for (unsigned i = 0; i < clCount; i++) {
        sf::Texture texture;
        texture.loadFromFile("../../Textures/Test" + std::to_string(i + 1) + ".png");
        texture.setSmooth(true);
        texturesSet.push_back(texture);
    } 
}

color_code ColorType(sf::Color color) {
    if (color == sf::Color::Green)
        return clGreen;
    if (color == sf::Color::Blue)
        return clBlue;
    if (color == sf::Color::Red)
        return clRed;
    if (color == sf::Color::Yellow)
        return clYellow;
    if (color == sf::Color::Cyan)
        return clCyan;
    if (color == sf::Color::Magenta)
        return clMagenta;
    if (color == sf::Color::Black)
        return clBlack;
    return clUnknown;
}

sf::Texture* GetTextureByColor(sf::Color color) {
    return &texturesSet[ColorType(color)];
}