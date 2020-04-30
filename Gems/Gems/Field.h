#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "Gem.h"
#include "Textures.h"

//Essential game class that keeps all gems as a matrix and allows all operations on them
class Field {
private:
    std::vector <std::vector <Gem>> gemsMatrix; //matrix of all gem objects on the screen
    std::array <sf::Color, 6> colorsSpectre = { sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta };    //possible colors array
    float width, height; //size of field taken from current window's size
    unsigned gemsInRow, gemsInColumn;   //amount of gems on the playfield
    std::vector <std::array <unsigned, 2>> matching; //global vector of matching gems, refreshed each time for a new combination
public:
    std::shared_ptr <TextureManager> texMng;

    //field constructor depending on current window's sizes and field's sizes; by default field is 10x10
    Field(float windowWidth, float windowHeight, unsigned gemsInRow, unsigned gemsInColumn);
    ~Field() {}

    void GenerateField(void);

    std::array<sf::Color, 6> GetColorsSpectre(void);

    unsigned GetGemsInRow();

    unsigned GetGemsInColumn();

    std::vector<std::array<unsigned, 2>> GetMatchingVector();

    //Drawing full playfield depending on gems matrix
    void DrawField(std::shared_ptr <sf::RenderWindow> window);

    unsigned CheckNeighboursColors(unsigned i, unsigned j, std::vector <Gem> tmp);

    void SetNewColors(std::vector<std::array<unsigned, 2>> painted, unsigned x, unsigned y);

    bool CheckFieldForMatching(void);
    void FieldDeletion(std::vector <std::array <unsigned, 2>> matching);
    bool AlreadyMatched(unsigned i, unsigned j);
    void CheckMatch(unsigned i, unsigned j);
    bool FieldDrop(void);
    void FieldRefill(void);
    void SetHighlighted(unsigned x, unsigned y);
    void RemoveHighlight(unsigned x, unsigned y);
    void Swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
};