#include "Gem.h"

//all parametrs are being evaluated in Field class constructor or any other additional Field class method
Gem::Gem(unsigned newWidth, unsigned newHeight, sf::Color newColor) {
    width = newWidth;
    height = newHeight;
    color = newColor;
}
