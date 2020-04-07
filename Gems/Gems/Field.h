#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "Gem.h"

//Essential game class that keeps all gems as a matrix and allows all operations on them
class Field {
private:
    std::vector <std::vector <Gem>> gemsMatrix; //matrix of all gem objects on the screen
    std::array <sf::Color, 6> colorsSpectre = { sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta };    //possible colors array
    unsigned width, height; //size of field taken from current window's size
    unsigned gemsInRow, gemsInColumn;   //amount of gems on the playfield
public:
    //field constructor depending on current window and field's sizes; by default field is 10x10
    Field(sf::RenderWindow window, unsigned gemsInRow, unsigned gemsInColumn);
};