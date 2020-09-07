#include "Painter.h"

Painter::Painter() {
    type = clPainter;
    triggerMessage = "*SWOOSH*";
    triggerColor = sf::Color::Magenta;
}

void Painter::Trigger(std::shared_ptr<Field> field) {
    std::vector <std::array <unsigned, 2>> painted;

    for (unsigned i = 0; i < paintedAmount; ++i) {
        unsigned xrand, yrand;

        do {
            int xRandomSign = (int)pow(-1, rand() % field->GetGemsInRow()); //randomly either 1 or -1
            int yRandomSign = (int)pow(-1, rand() % field->GetGemsInColumn()); //randomly either 1 or -1

            unsigned xRandomCoordinate = (rand() % (paintedRadius - 1) + 2); //randomly from 2 to 3
            unsigned yRandomCoordinate = (rand() % (paintedRadius - 1) + 2); //randomly from 2 to 3

            xrand = x + xRandomSign * xRandomCoordinate;
            yrand = y + yRandomSign * yRandomCoordinate;
        } while (xrand >= field->GetGemsInRow() || yrand >= field->GetGemsInColumn());

        painted.push_back({ xrand, yrand });
    }

    field->SetNewColors(painted, x, y);
}