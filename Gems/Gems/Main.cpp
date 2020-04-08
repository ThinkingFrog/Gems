#include "Main.h"

int main(void) {

    srand((unsigned)time(0));   //random gems' colors generation

    unsigned fieldWidth = 3, fieldHeight = 3; //Amount of gems in row and in column
    unsigned userResolutionWidth = 1080, userResolutionHeight = 720;    //Window resolution

    sf::RenderWindow window(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems");

    float windowWidth = (float)window.getSize().x, windowHeight = (float)window.getSize().y;

    Field field(windowWidth, windowHeight, fieldWidth, fieldHeight);

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //drawing field
        field.DrawField(&window);
        field.CheckFieldForMatching();
        field.FieldDrop();
        field.FieldRefill();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            float mouseX = (float)localPosition.x;
            float mouseY = (float)localPosition.y;
            unsigned gemX = (unsigned)(mouseX / (windowWidth / fieldWidth));
            unsigned gemY = (unsigned)(mouseY / (windowHeight / fieldHeight));
            field.SetHighlited(&window, gemX, gemY);
        }

        //Time between frames
        sf::Clock timer;
        while (timer.getElapsedTime().asSeconds() < 0.25);

        window.display();
    }

    return 0;
}