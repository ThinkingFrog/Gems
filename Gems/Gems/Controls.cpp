#include "Field.h"

void Field::SetHighlited(sf::RenderWindow *window, unsigned x, unsigned y) {
    gemsMatrix[x][y].DrawGem(window, (float)x * (float)(*window).getSize().x / gemsInRow, (float)y * (float)(*window).getSize().y / gemsInColumn, sf::Color::Yellow);
}