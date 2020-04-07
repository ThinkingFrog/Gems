#include "Main.h"

int main(void) {

    srand((unsigned)time(0));   //random gems' colors generation

    unsigned fieldWidth = 10, fieldHeight = 10; //Amount of gems in row and in column
    unsigned userResolutionWidth = 1080, userResolutionHeight = 720;    //Window resolution

    sf::RenderWindow window(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems");

    float windowWidth = (float)window.getSize().x, windowwHeight = (float)window.getSize().y;

    Field field(windowWidth, windowwHeight, fieldWidth, fieldHeight);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //drawing full field
        field.DrawField(&window);

        window.display();
    }

    return 0;
}