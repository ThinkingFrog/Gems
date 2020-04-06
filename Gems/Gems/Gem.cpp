#include "Gem.h"
#include <cstdlib>

Gem::Gem(sf::RenderWindow window) {
    width = window.getSize().x / 10;
    height = window.getSize().y / 10;
    color = possibleColors[rand() % possibleColors.size()];
}
