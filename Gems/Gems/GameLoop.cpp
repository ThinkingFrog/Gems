#include <cmath>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Field.h"
#include "Main.h"
#include "Textures.h"
#include "Bonuses.h"
#include "Font.h"

extern std::vector <std::array <unsigned, 2>> matching;

void GameLoop(void) {

    bool secondClick = false;
    bool dropped = false;
    bool bonusSpawned = false;
    bool deleted = false;
    bool bonusTriggered = false;
    bool hasFocus = true;

    unsigned gem1X, gem1Y, gem2X, gem2Y;

    sf::RenderWindow window(sf::VideoMode(userResolutionWidth, userResolutionHeight), "Gems", sf::Style::Close);
    window.setFramerateLimit(1);

    std::shared_ptr <Field> field(new Field((float)userResolutionWidth, (float)userResolutionHeight, fieldWidth, fieldHeight));

    std::shared_ptr <Bonus> bonus;

    InitTexturesSet();
    InitFont();

    while (window.isOpen()) {

        hasFocus = true;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::LostFocus)
                hasFocus = false;
        }

        if (hasFocus == false)
            continue;

        window.clear();

        deleted = false;
        bonusTriggered = false;

        if (bonusSpawned == true) {
            bonus->Trigger(field);
            bonusSpawned = false;
            bonusTriggered = true;
        }

        if (dropped == false && bonusTriggered == false)
            deleted = field->CheckFieldForMatching();
        dropped = field->FieldDrop();
        if (dropped == false)
            field->FieldRefill();

        if (deleted == true) {
            if (rand() % 100 < BONUS_CHANCE * matching.size()) {
                switch (rand() % BONUS_COUNT) {
                case 0:
                    bonus = std::make_shared<Painter>();
                    break;
                case 1:
                    bonus = std::make_shared<Bomb>();
                    break;
                }
                bonus->SetPosition(matching[0][0], matching[0][1]);
                bonusSpawned = true;
            }
        }

        //swap controls
        if (dropped == false)
            if (secondClick == false) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    sf::Vector2i localPosition1 = sf::Mouse::getPosition(window);
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

                    sf::Vector2i localPosition2 = sf::Mouse::getPosition(window);
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

        //drawing field
        field->DrawField(&window);

        if (bonusSpawned == true)
            bonus->DrawBonus(&window, field, bonus->GetType());

        window.display();
    }
}