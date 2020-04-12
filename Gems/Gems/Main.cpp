#include "Main.h"

int main(void) {

    srand((unsigned)time(0));   //random gems' colors generation

    bool wait = false;

    unsigned fieldWidth = 10, fieldHeight = 10; //Amount of gems in row and in column
    unsigned userResolutionWidth = 800, userResolutionHeight = 600;    //Window resolution

    unsigned gem1X, gem1Y, gem2X, gem2Y;

    sf::RenderWindow window(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems");

    float windowWidth = (float)window.getSize().x, windowHeight = (float)window.getSize().y;

    Field field(windowWidth, windowHeight, fieldWidth, fieldHeight);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            //  if (event.type == sf::Event::KeyPressed)
              //    wait = false;
        }

        window.clear();

        //drawing field
        field.CheckFieldForMatching();
        field.FieldDrop();
        field.FieldRefill();

        if (wait == true) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                sf::Vector2i localPosition2 = sf::Mouse::getPosition(window);
                float mouse2X = (float)localPosition2.x;
                float mouse2Y = (float)localPosition2.y;
                gem2X = (unsigned)(mouse2X / (windowWidth / fieldWidth));
                gem2Y = (unsigned)(mouse2Y / (windowHeight / fieldHeight));
                field.Swap(gem1X, gem1Y, gem2X, gem2Y);
                field.RemoveHighlight(gem1X, gem1Y);
                wait = false;
            }
        }

        if (wait == false) {
            //Swap controls
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                sf::Vector2i localPosition1 = sf::Mouse::getPosition(window);
                float mouse1X = (float)localPosition1.x;
                float mouse1Y = (float)localPosition1.y;
                gem1X = (unsigned)(mouse1X / (windowWidth / fieldWidth));
                gem1Y = (unsigned)(mouse1Y / (windowHeight / fieldHeight));
                field.SetHighlighted(gem1X, gem1Y);
                wait = true;
            }
        }

        field.DrawField(&window);

        //Time between frames
        sf::Clock timer;
        while (timer.getElapsedTime().asSeconds() < 0.25);

        window.display();
    }

    return 0;
}