#include "Field.h"

bool Field::FieldDrop() {
    bool dropped = false;
    for (unsigned j = 0; j < gemsInColumn - 1; j++)
        for (unsigned i = 0; i < gemsInRow; i++)
            if (!gemsMatrix[j][i].IsEmpty() && gemsMatrix[j + 1][i].IsEmpty()) {
                gemsMatrix[j + 1][i].SetColor(gemsMatrix[j][i].GetColor());
                gemsMatrix[j][i].SetEmpty();
                dropped = true;
            }
    return dropped;
}

void Field::FieldRefill() {
    for (unsigned j = 0; j < gemsInColumn; j++)
        for (unsigned i = 0; i < gemsInRow; i++)
            if (gemsMatrix[j][i].IsEmpty())
                gemsMatrix[j][i].SetColor(colorsSpectre[rand() % colorsSpectre.size()]);
}