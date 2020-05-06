#include <cstdlib>
#include <string>
#include "Bonus.h"
#include "Main.h"
#include "Field.h"

void Bonus::SetPosition(unsigned xnew, unsigned ynew) {
    x = xnew;
    y = ynew;
}

void Bonus::DrawBonus(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<Field> field) {

    float windowWidth = (float)window->getSize().x;
    float windowHeight = (float)window->getSize().y;

    float width = windowWidth / field->GetGemsInRow();
    float height = windowHeight / field->GetGemsInColumn();

    //average of width and height multiplied by 0.075 which is an optimal number found by experementing with outline sizes
    float outlineSize = (float)(-(width + height) / 2 * 0.075);

    bool applyTex = !field->texMng->TexturesSetIsDamaged();

    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition((float)x * width, (float)y * height);
    shape.setOutlineThickness(outlineSize);
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

void Bonus::ShowTriggerText(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr <Field> field) {

    sf::Text text;

    float windowWidth = (float)window->getSize().x;
    float windowHeight = (float)window->getSize().y;

    float width = windowWidth / field->GetGemsInRow();
    float height = windowHeight / field->GetGemsInColumn();

    text.setFont(field->texMng->font);
    text.setString(triggerMessage);
    text.setCharacterSize((unsigned)(width + height) / 10);
    text.setFillColor(triggerColor);
    text.setStyle(sf::Text::Bold);
    text.setPosition((float)x * width, (float)y * height + height / 2);

    window->draw(text);
}