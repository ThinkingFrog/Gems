#include "Gem.h"

//all parametrs are being evaluated in Field class constructor or any other additional Field class method
Gem::Gem(float newWidth, float newHeight, sf::Color newColor) {
    width = newWidth;
    height = newHeight;
    color = newColor;
}

//function returns an SFML drawable shape to be drawn via window.draw()
void Gem::DrawGem(sf::RenderWindow *window, float x, float y) {
    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setFillColor(color);
    shape.setPosition(x, y);
    shape.setOutlineThickness((width + height) / 2 * 0.1);
    shape.setOutlineColor(sf::Color::Black);
    (*window).draw(shape);
}
