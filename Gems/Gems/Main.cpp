#include "Main.h"

int main(void) {

    srand((unsigned)time(0));   //random gems' colors generation

    bool secondClick = false;
    bool dropped = false;

    unsigned gem1X = 0, gem1Y = 0, gem2X = 0, gem2Y = 0;

    unsigned fieldWidth = 10, fieldHeight = 10; //Amount of gems in row and in column
    unsigned userResolutionWidth = 800, userResolutionHeight = 600;    //Window resolution

    sf::RenderWindow window(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems");

    Field field((float)userResolutionWidth, (float)userResolutionHeight, fieldWidth, fieldHeight);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //drawing field
        if (dropped == false)
            field.CheckFieldForMatching();
        dropped = field.FieldDrop();
        if (dropped == false)
            field.FieldRefill();

        //swap controls
        if (dropped == false)
            if (secondClick == false) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    sf::Vector2i localPosition1 = sf::Mouse::getPosition(window);
                    float mouse1X = (float)localPosition1.x;
                    float mouse1Y = (float)localPosition1.y;
                    gem1X = (unsigned)(mouse1X / (float)(userResolutionWidth / fieldWidth));
                    gem1Y = (unsigned)(mouse1Y / (float)(userResolutionHeight / fieldHeight));
                    field.SetHighlighted(gem1X, gem1Y);
                    secondClick = true;
                }
            }
            else
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    sf::Vector2i localPosition2 = sf::Mouse::getPosition(window);
                    float mouse2X = (float)localPosition2.x;
                    float mouse2Y = (float)localPosition2.y;
                    gem2X = (unsigned)(mouse2X / (float)(userResolutionWidth / fieldWidth));
                    gem2Y = (unsigned)(mouse2Y / (float)(userResolutionHeight / fieldHeight));
                    if (abs((int)gem2X - (int)gem1X) <= 1 && abs((int)gem2Y - (int)gem1Y) <= 1 && !(abs((int)gem2X - (int)gem1X) == 1 && abs((int)gem2Y - (int)gem1Y) == 1)) {
                        field.Swap(gem1X, gem1Y, gem2X, gem2Y);
                        field.RemoveHighlight(gem1X, gem1Y);
                        secondClick = false;
                    }
                }

        field.DrawField(&window);

        window.display();

        //Time between frames
        sf::Clock timer;
        while (timer.getElapsedTime().asSeconds() < 0.25);
    }

    return 0;
}