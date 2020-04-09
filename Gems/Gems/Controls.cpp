#include "Field.h"

void Field::SetHighlited(sf::RenderWindow *window, unsigned x, unsigned y) {
    gemsMatrix[y][x].DrawGem(window, (float)x * (float)(*window).getSize().x / gemsInRow, (float)y * (float)(*window).getSize().y / gemsInColumn, sf::Color::Yellow);
}

void Field::Swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
    sf::Color color1, color2;
    color1 = gemsMatrix[y1][x1].GetColor();
    color2 = gemsMatrix[y2][x2].GetColor();
    gemsMatrix[y1][x1].SetColor(color1);
    gemsMatrix[y2][x2].SetColor(color2);
}