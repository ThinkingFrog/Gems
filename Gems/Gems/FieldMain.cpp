#include <cstdlib>
#include "Field.h"

Field::Field(float windowWidth, float windowHeight, unsigned gemsInRow, unsigned gemsInColumn) {
    width = windowWidth;
    height = windowHeight;
    this->gemsInRow = gemsInRow;
    this->gemsInColumn = gemsInColumn;
    GenerateField();
}

void Field::GenerateField(void) {
    for (unsigned i = 0; i < gemsInColumn; i++) {
        std::vector <Gem> tmp;
        for (unsigned j = 0; j < gemsInRow; j++) {
            Gem gem((float)(width / gemsInRow), (float)(height / gemsInColumn), colorsSpectre[rand() % colorsSpectre.size()]);
            tmp.push_back(gem);
            while (CheckNeighboursColors(i, j, tmp) >= 2)
                tmp[j].SetColor(colorsSpectre[rand() % colorsSpectre.size()]);
        }
        gemsMatrix.push_back(tmp);
    }
}

std::array <sf::Color, 6> Field::GetColorsSpectre(void) {
    return colorsSpectre;
}

void Field::DrawField(sf::RenderWindow* window) {
    float windowWidth = (float)(*window).getSize().x, windowwHeight = (float)(*window).getSize().y;
    for (unsigned i = 0; i < gemsInColumn; i++)
        for (unsigned j = 0; j < gemsInRow; j++)
            gemsMatrix[i][j].DrawGem(window, (float)j * windowWidth / gemsInRow, (float)i * windowwHeight / gemsInColumn);
}

unsigned Field::CheckNeighboursColors(unsigned i, unsigned j, std::vector <Gem> tmp) {

    unsigned sum = 0;

    //upper left
    if (i != 0 && j != 0)
        if (tmp[j].GetColor() == gemsMatrix[i - 1][j - 1].GetColor())
            sum += 1;

    //upper
    if (i != 0)
        if (tmp[j].GetColor() == gemsMatrix[i - 1][j].GetColor())
            sum += 1;

    //upper right
    if (i != 0 && j != gemsInRow - 1)
        if (tmp[j].GetColor() == gemsMatrix[i - 1][j + 1].GetColor())
            sum += 1;
    //left
    if (j != 0)
        if (tmp[j].GetColor() == tmp[j - 1].GetColor())
            sum += 1;

    return sum;
}