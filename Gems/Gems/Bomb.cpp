#include "Bomb.h"

Bomb::Bomb() {
    type = clBomb;
    triggerMessage = "*BOOM*";
    triggerColor = sf::Color::Red;
}

void Bomb::Trigger(std::shared_ptr<Field> field) {
    std::vector <std::array <unsigned, 2>> bombed;
    bombed.push_back({ x, y });

    for (unsigned i = 0; i < bombedAmount - 1; ++i)
        bombed.push_back({ rand() % field->GetGemsInRow(), rand() % field->GetGemsInColumn() });

    field->FieldDeletion(bombed);
}