#include "Gem.h"

//all parametrs are being evaluated in Field class constructor or any other additional Field class method
Gem::Gem(float newWidth, float newHeight, sf::Color newColor) {
    width = newWidth;
    height = newHeight;
    color = newColor;
}

sf::Color Gem::GetColor(void) {
    return color;
}

void Gem::SetEmpty(void) {
    color = sf::Color::Black;
}

void Gem::SetColor(sf::Color newColor) {
    color = newColor;
}

bool Gem::IsEmpty(void) {
    if (color == sf::Color::Black)
        return true;
    return false;
}

//function returns an SFML drawable shape to be drawn via window.draw()
void Gem::DrawGem(sf::RenderWindow *window, float x, float y, sf::Color outline) {
    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setFillColor(color);
    shape.setPosition(x, y);
    shape.setOutlineThickness((width + height) / 2 * 0.1);
    shape.setOutlineColor(outline);
    (*window).draw(shape);
}
