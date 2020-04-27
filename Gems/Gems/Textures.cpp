#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <map>
#include "Textures.h"

std::map <color_code, sf::Texture> texturesSet;

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

void InitTexturesSet(void) {

    std::map <color_code, std::string> colorsSet = { {clGreen, "Green"}, {clBlue, "Blue"}, {clRed, "Red"}, {clYellow, "Yellow"},
        {clCyan, "Cyan"}, {clMagenta, "Magenta"}, {clBlack, "Black"} };

    std::string localPath = "../../Textures/";
    std::fstream file;
    file.open(localPath + colorsSet.begin()->second + ".png");
    if (file.fail())
        localPath = "../../../Textures/";
    file.close();

    for (auto it = colorsSet.begin(); it != colorsSet.end(); ++it) {
        sf::Texture texture;
        texture.loadFromFile(localPath + it->second + ".png");
        texture.setSmooth(true);
        texturesSet[it->first] = texture;
    }
}

sf::Texture* GetTextureByColor(sf::Color color) {
    return &texturesSet.find(ColorType(color))->second;
}