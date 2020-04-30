#include <string>
#include "Font.h"

sf::Font font;

void InitFont() {
    std::string localPath = "../../Textures/";
    std::string fontName = "default_font";

    font.loadFromFile(localPath + fontName + ".ttf");
}