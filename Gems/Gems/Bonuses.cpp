#include <cstdlib>
#include <string>
#include "Bonuses.h"
#include "Main.h"
#include "Field.h"

void Bonus::SetPosition(unsigned xnew, unsigned ynew) {
    x = xnew;
    y = ynew;
}

void Bonus::DrawBonus(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<Field> field) {

    float width = (float)window->getSize().x / field->GetGemsInRow(), height = (float)window->getSize().y / field->GetGemsInColumn();
    bool applyTex = !field->texMng->TexturesSetIsDamaged();

    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition((float)x * width, (float)y * height);
    shape.setOutlineThickness((float)(-(width + height) / 2 * 0.075));
    shape.setOutlineColor(sf::Color::Black);

    if (applyTex) {
        sf::Texture texture;
        shape.setTexture(field->texMng->GetTextureByCode(type));
    }
    else
        shape.setFillColor(sf::Color::White);

    window->draw(shape);
    ShowTriggerText(window, field);
}

void Bonus::ShowTriggerText(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr <Field> field){
    
    sf::Text text;

    float width = (float)window->getSize().x / field->GetGemsInRow(), height = (float)window->getSize().y / field->GetGemsInColumn();

    text.setFont(field->texMng->font);
    text.setString(triggerMessage);
    text.setCharacterSize((unsigned)(width + height) / 10);
    text.setFillColor(triggerColor);
    text.setStyle(sf::Text::Bold);
    text.setPosition((float)x * width, (float)y * height + height / 2);

    window->draw(text);
}

void Bomb::Trigger(std::shared_ptr<Field> field) {
    std::vector <std::array <unsigned, 2>> bombed;
    bombed.push_back({ x, y });

    for (unsigned i = 0; i < bombedAmount - 1; ++i)
        bombed.push_back({rand() % field->GetGemsInRow(), rand() % field->GetGemsInColumn()});

    field->FieldDeletion(bombed);
}

void Painter::Trigger(std::shared_ptr<Field> field) {
    std::vector <std::array <unsigned, 2>> painted;

    for (unsigned i = 0; i < paintedAmount; ++i) {
        unsigned xrand, yrand;
        
        do {
            xrand = x + (int)pow(-1, rand() % field->GetGemsInRow()) * (rand() % (paintedRadius - 1) + 2);
            yrand = y + (int)pow(-1, rand() % field->GetGemsInColumn()) * (rand() % (paintedRadius - 1) + 2);
        } while (xrand >= field->GetGemsInRow() || yrand >= field->GetGemsInColumn());

        painted.push_back({ xrand, yrand });
    }

    field->SetNewColors(painted, x, y);
}