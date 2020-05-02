#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <map>
#include "Textures.h"

/**
*Associates color and color_code to be able to load textures simply by gem's color
*/
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
}

TextureManager::TextureManager() {

    std::string localPath = "../../Textures/";

    std::fstream file;
    for (auto it = colorsSet.begin(); it != colorsSet.end(); ++it) {
        file.open(localPath + it->second + ".png");
        if (file.fail())
            return;
        file.close();
    }

    for (auto it = colorsSet.begin(); it != colorsSet.end(); ++it) {
        sf::Texture texture;
        texture.loadFromFile(localPath + it->second + ".png");
        texture.setSmooth(true);
        texturesSet[it->first] = texture;
    }

    std::string fontName = "default_font";

    font.loadFromFile(localPath + fontName + ".ttf");
}

sf::Texture* TextureManager::GetTextureByColor(sf::Color color) {
    return &texturesSet[ColorType(color)];
}

sf::Texture* TextureManager::GetTextureByCode(color_code code) {
    return &texturesSet[code];
}

bool TextureManager::TexturesSetIsDamaged() {
    return (texturesSet.size() != colorsSet.size());
}