#include "Field.h"

void Field::SetHighlighted(unsigned x, unsigned y) {
    gemsMatrix[y][x].SetOutlineColor(sf::Color::Yellow);
}

void Field::RemoveHighlight(unsigned x, unsigned y) {
    gemsMatrix[y][x].SetOutlineColor(sf::Color::Black);
}

void Field::Swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
    sf::Color color1, color2;
    color1 = gemsMatrix[y1][x1].GetColor();
    color2 = gemsMatrix[y2][x2].GetColor();
    gemsMatrix[y1][x1].SetColor(color2);
    gemsMatrix[y2][x2].SetColor(color1);
}