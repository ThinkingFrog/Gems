#pragma once

#include "Main.h"

class TextureManager {
private:
    std::map <color_code, sf::Texture> texturesSet;
    std::map <color_code, std::string> colorsSet = { {clGreen, "Green"}, {clBlue, "Blue"}, {clRed, "Red"}, {clYellow, "Yellow"},
        {clCyan, "Cyan"}, {clMagenta, "Magenta"}, {clBlack, "Black"}, {clBomb, "Bomb"}, {clPainter, "Painter"} };
public:
    TextureManager();
    ~TextureManager() {}
    sf::Texture* GetTextureByColor(sf::Color color);
    sf::Texture* GetTextureByCode(color_code code);
    bool TexturesSetIsDamaged();
};