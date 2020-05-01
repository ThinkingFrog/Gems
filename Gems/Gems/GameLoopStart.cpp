#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
#include "Menu.h"
#include "Field.h"
#include "Main.h"
#include "Textures.h"
#include "Bonuses.h"
#include "GameLoop.h"

void GameLoop::Start() {

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
}