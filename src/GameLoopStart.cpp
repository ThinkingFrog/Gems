#include <SFML/Graphics.hpp>
#include "GameLoop.h"

void GameLoop::Start(Menu menu) {

    fieldWidth = menu.GetFieldWidth();
    fieldHeight = menu.GetFieldHeight();
    userResolutionWidth = menu.GetUserResolutionWidth();
    userResolutionHeight = menu.GetUserResolutionHeight();

    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems", sf::Style::Close);
    window->setFramerateLimit(FRAME_RATE);
    field = std::make_shared<Field>((float)userResolutionWidth, (float)userResolutionHeight, fieldWidth, fieldHeight);

    while (window->isOpen()) {

        CheckEvents();
        
        if (hasFocus == false)
            continue;

        window->clear();

        deleted = false;    //no combinations deleted on current frame yet
        bonusTriggered = false; //no bonus triggered on current frame yet

        //trigger bonus if it was spawned on last frame
        if (bonusSpawned == true)
            TriggerBonus();

        //check for any combinations on field, drop available gems and refill empty spaces
        ProcessField();
        
        //if any combination was deleted on current frame, try to spawn bonus
        if (deleted == true)
            SpawnBonus();

        //if no gem was dropped on current frame, allow contols
        if (dropped == false)
            MouseControls();
        
        //draw all gems on the field
        field->DrawField(window);

        //if any bonus was spawned on current frame, draw it above gems
        if (bonusSpawned == true)
            bonus->DrawBonus(window, field);

        window->display();
    }

    window.reset();
    field.reset();
}