#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Gem {
private:
    unsigned width, height;
    std::array <sf::Color, 3> possibleColors = { sf::Color::Green, sf::Color::Blue, sf::Color::Red };
    sf::Color color;

public:
    Gem(sf::RenderWindow window);
};

