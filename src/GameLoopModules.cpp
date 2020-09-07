#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
#include <cmath>
#include "Menu.h"
#include "Field.h"
#include "Main.h"
#include "Textures.h"
#include "Bonus.h"
#include "Bomb.h"
#include "Painter.h"
#include "GameLoop.h"

GameLoop::GameLoop() {
    secondClick = false;
    dropped = false;
    bonusSpawned = false;
    deleted = false;
    bonusTriggered = false;
    hasFocus = true;
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
    //if previos frame didn't cause any gems to drop and no bonus was triggered on current frame, check gems combinations
    if (dropped == false && bonusTriggered == false)
        deleted = field->CheckFieldForMatching();

    dropped = field->FieldDrop();

    //if FieldDrop() didn't cause any gems to drop, refill all empty spaces
    if (dropped == false)
        field->FieldRefill();
}

void GameLoop::SetRandomPoint(unsigned& spawnX, unsigned& spawnY) {
    do {
        int xRandomSign = (int)pow(-1, rand() % fieldWidth); //randomly either 1 or -1
        int yRandomSign = (int)pow(-1, rand() % fieldHeight); //randomly either 1 or -1

        unsigned xRandomCoordinate = (rand() % BONUS_SPAWN_RADIUS + 1); //randomly from 1 to 3
        unsigned yRandomCoordinate = (rand() % BONUS_SPAWN_RADIUS + 1); //randomly from 1 to 3

        unsigned xStartingPoint = field->GetMatchingVector()[0][0];
        unsigned yStartingPoint = field->GetMatchingVector()[0][1];

        spawnX = xStartingPoint + xRandomSign * xRandomCoordinate;
        spawnY = yStartingPoint + yRandomSign * yRandomCoordinate;
    } while (spawnX >= fieldWidth || spawnY >= fieldHeight);
}

void GameLoop::SelectBonusType() {
    switch (rand() % BONUS_COUNT) {
    case 0:
        bonus = std::make_shared<Painter>();
        break;
    case 1:
        bonus = std::make_shared<Bomb>();
        break;
    }
}

void GameLoop::SpawnBonus() {
    if (rand() % 100 < BONUS_CHANCE * field->GetMatchingVector().size()) {
        SelectBonusType();

        unsigned spawnX, spawnY;

        SetRandomPoint(spawnX, spawnY);

        bonus->SetPosition(spawnX, spawnY);
        bonusSpawned = true;
    }
}

void GameLoop::SelectFirstGem() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i localPosition1 = sf::Mouse::getPosition(*window);
        float mouse1X = (float)localPosition1.x;
        float mouse1Y = (float)localPosition1.y;
        gem1X = (unsigned)(mouse1X / (float)(userResolutionWidth / fieldWidth));
        gem1Y = (unsigned)(mouse1Y / (float)(userResolutionHeight / fieldHeight));
        field->SetHighlighted(gem1X, gem1Y);
        secondClick = true;
    }
}

void GameLoop::CancelSelection() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        field->RemoveHighlight(gem1X, gem1Y);
        secondClick = false;
    }
}

void GameLoop::SelectSecondGem() {
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
        CancelSelection();
}

void GameLoop::MouseControls() {
    if (secondClick == false)
        SelectFirstGem();
    else
        SelectSecondGem();
}