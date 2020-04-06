#include "Main.h"

int main(void) {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    sf::CircleShape shape(100.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}