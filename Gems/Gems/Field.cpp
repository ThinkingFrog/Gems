#include <cstdlib>
#include "Field.h"

Field::Field(sf::RenderWindow window, unsigned gemsInRow = 10, unsigned gemsInColumn = 10) {
    width = window.getSize().x;
    height = window.getSize().y;
    for (unsigned i = 0; i < gemsInColumn; i++) {
        std::vector <Gem> tmp;
        for (unsigned j = 0; j < gemsInRow; j++) {
            Gem gem(width / gemsInRow, height / gemsInColumn, colorsSpectre[rand() % colorsSpectre.size()]);
            tmp.push_back(gem);
        }
        gemsMatrix.push_back(tmp);
    }
}