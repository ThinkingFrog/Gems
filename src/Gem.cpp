#include "Gem.h"
#include "Textures.h"
#include "Main.h"
#include "Field.h"

Gem::Gem(float newWidth, float newHeight, sf::Color newColor) {
    width = newWidth;
    height = newHeight;
    color = newColor;
    outline = sf::Color::Black;
}

sf::Color Gem::GetColor() {
    return color;
}

void Gem::SetEmpty() {
    color = sf::Color::Black;
}

void Gem::SetColor(sf::Color newColor) {
    color = newColor;
}

void Gem::SetOutlineColor(sf::Color newOutline) {
    outline = newOutline;
}

bool Gem::IsEmpty() {
    if (color == sf::Color::Black)
        return true;
    return false;
}

//function returns an SFML drawable shape to be drawn via window.draw()
void Gem::DrawGem(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<TextureManager> texMng, float x, float y) {

    //average of width and height multiplied by 0.075 which is an optimal number found by experementing with outline sizes
    float outlineSize = (float)(-(width + height) / 2 * 0.075);

    bool applyTex = !texMng->TexturesSetIsDamaged();

    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setOutlineThickness(outlineSize);
    shape.setOutlineColor(outline);

    if (applyTex) {
        sf::Texture* texture = texMng->GetTextureByColor(color);
        shape.setTexture(texture);
    }
    else
        shape.setFillColor(color);

    window->draw(shape);
}