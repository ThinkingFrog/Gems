#include <cstdlib>
#include "Field.h"

Field::Field(float windowWidth, float windowHeight, unsigned gemsInRow, unsigned gemsInColumn) {
    width = windowWidth;
    height = windowHeight;
    this->gemsInRow = gemsInRow;
    this->gemsInColumn = gemsInColumn;
    for (unsigned i = 0; i < gemsInColumn; i++) {
        std::vector <Gem> tmp;
        for (unsigned j = 0; j < gemsInRow; j++) {
            Gem gem((float)(width / gemsInRow), (float)(height / gemsInColumn), colorsSpectre[rand() % colorsSpectre.size()]);
            tmp.push_back(gem);
        }
        gemsMatrix.push_back(tmp);
    }
}

std::vector <std::vector <Gem>> Field::GetGemsMatrix(void) {
    return gemsMatrix;
}

void Field::DrawField(sf::RenderWindow *window) {
    float windowWidth = (float)(*window).getSize().x, windowwHeight = (float)(*window).getSize().y;
    for (unsigned i = 0; i < gemsInRow; i++)
        for (unsigned j = 0; j < gemsInColumn; j++)
            gemsMatrix[i][j].DrawGem(window, (float)j * windowWidth / gemsInRow, (float)i * windowwHeight / gemsInColumn);
}
