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
    float width, height; //size of field taken from current window's size
    unsigned gemsInRow, gemsInColumn;   //amount of gems on the playfield
public:
    //field constructor depending on current window's sizes and field's sizes; by default field is 10x10
    Field(float windowWidth, float windowHeight, unsigned gemsInRow, unsigned gemsInColumn);

    void GenerateField(void);

    //Drawing full playfield depending on gems matrix
    void DrawField(sf::RenderWindow *window);

    unsigned CheckNeighboursColors(unsigned i, unsigned j, std::vector <Gem> tmp);


    void CheckFieldForMatching(void);
    void FieldDeletion(std::vector <std::array <unsigned, 2>> matching);
    void CheckMatch(unsigned i, unsigned j);
    bool FieldDrop(void);
    void FieldRefill(void);
    void SetHighlighted(unsigned x, unsigned y);
    void RemoveHighlight(unsigned x, unsigned y);
    void Swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
};