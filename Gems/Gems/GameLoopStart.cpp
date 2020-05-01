#include <SFML/Graphics.hpp>
#include "GameLoop.h"

void GameLoop::Start() {

    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems", sf::Style::Close);
    window->setFramerateLimit(FRAME_RATE);
    field = std::make_shared<Field>((float)userResolutionWidth, (float)userResolutionHeight, fieldWidth, fieldHeight);

    while (window->isOpen()) {

        CheckEvents();

        if (hasFocus == false)
            continue;

        window->clear();

        deleted = false;
        bonusTriggered = false;

        if (bonusSpawned == true)
            TriggerBonus();

        ProcessField();

        if (deleted == true)
            SpawnBonus();

        if (dropped == false)
            MouseControls();

        field->DrawField(window);

        if (bonusSpawned == true)
            bonus->DrawBonus(window, field);

        window->display();
    }

    window.reset();
    field.reset();
}