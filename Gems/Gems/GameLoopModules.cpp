#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
#include "Menu.h"
#include "Field.h"
#include "Main.h"
#include "Textures.h"
#include "Bonuses.h"
#include "GameLoop.h"

GameLoop::GameLoop() {
    secondClick = false;
    dropped = false;
    bonusSpawned = false;
    deleted = false;
    bonusTriggered = false;
    hasFocus = true;
    window = std::make_shared<sf::RenderWindow>((userResolutionWidth, userResolutionHeight), "Gems", sf::Style::Close);
    window->setFramerateLimit(FRAME_RATE);
    field = std::make_shared<Field>((float)userResolutionWidth, (float)userResolutionHeight, fieldWidth, fieldHeight);
}

void GameLoop::CheckEvents() {

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::LostFocus)
            hasFocus = false;
        if (event.type == sf::Event::GainedFocus)
            hasFocus = true;
    }
}

void GameLoop::TriggerBonus() {

        bonus->Trigger(field);
        bonusSpawned = false;
        bonusTriggered = true;
        bonus.reset();
}

void GameLoop::ProcessField() {

    if (dropped == false && bonusTriggered == false)
        deleted = field->CheckFieldForMatching();
    dropped = field->FieldDrop();
    if (dropped == false)
        field->FieldRefill();
}

void GameLoop::SpawnBonus() {

    if (rand() % 100 < BONUS_CHANCE * field->GetMatchingVector().size()) {
        switch (rand() % BONUS_COUNT) {
        case 0:
            bonus = std::make_shared<Painter>();
            break;
        case 1:
            bonus = std::make_shared<Bomb>();
            break;
        }

        unsigned spawnX, spawnY;

        do {
            spawnX = field->GetMatchingVector()[0][0] + (int)pow(-1, rand() % fieldWidth) * (rand() % BONUS_SPAWN_RADIUS + 1);
            spawnY = field->GetMatchingVector()[0][1] + (int)pow(-1, rand() % fieldHeight) * (rand() % BONUS_SPAWN_RADIUS + 1);
        } while (spawnX >= fieldWidth || spawnY >= fieldHeight);

        bonus->SetPosition(spawnX, spawnY);
        bonusSpawned = true;
    }
}

void GameLoop::MouseControls() {

    if (secondClick == false) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2i localPosition1 = sf::Mouse::getPosition(*window);
            float mouse1X = (float)localPosition1.x;
            float mouse1Y = (float)localPosition1.y;
            gem1X = (unsigned)(mouse1X / (float)(userResolutionWidth / fieldWidth));
            gem1Y = (unsigned)(mouse1Y / (float)(userResolutionHeight / fieldHeight));
            field->SetHighlighted(gem1X, gem1Y);
            secondClick = true;
        }
    }
    else
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2i localPosition2 = sf::Mouse::getPosition(*window);
            float mouse2X = (float)localPosition2.x;
            float mouse2Y = (float)localPosition2.y;
            gem2X = (unsigned)(mouse2X / (float)(userResolutionWidth / fieldWidth));
            gem2Y = (unsigned)(mouse2Y / (float)(userResolutionHeight / fieldHeight));
            if (abs((int)gem2X - (int)gem1X) <= 1 && abs((int)gem2Y - (int)gem1Y) <= 1 && !(abs((int)gem2X - (int)gem1X) == 1 && abs((int)gem2Y - (int)gem1Y) == 1)) {
                field->Swap(gem1X, gem1Y, gem2X, gem2Y);
                field->RemoveHighlight(gem1X, gem1Y);
                secondClick = false;
            }
        }
        else
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                field->RemoveHighlight(gem1X, gem1Y);
                secondClick = false;
            }
}