#pragma once

#include <memory>
#include "Field.h"
#include "Textures.h"

class Bonus {
protected:
    color_code type;
    unsigned x, y;
    std::string triggerMessage;
    sf::Color triggerColor;
public:
    Bonus() : x(0), y(0) {}
    color_code GetType() { return type; }
    virtual void Trigger(std::shared_ptr<Field> field) = 0;
    void SetPosition(unsigned xnew, unsigned ynew);
    void DrawBonus(sf::RenderWindow* window, std::shared_ptr<Field> field, color_code bonusType);
    void ShowTriggerText(sf::RenderWindow* window, std::string message, sf::Color color);
};

class Bomb : public Bonus {
private:
    unsigned bombedAmount = 5;
public:
    Bomb() { type = clBomb; triggerMessage = "*BOOM*", triggerColor = sf::Color::Red;}
    void Trigger(std::shared_ptr<Field> field) override;
};

class Painter : public Bonus {
private:
    //bonus will paint [paintedAmount] random gems in radius from 2 to [paintedRadius] both including
    unsigned paintedAmount = 2;
    unsigned paintedRadius = 3;     
public:
    Painter() { type = clPainter; triggerMessage = "*SWOOSH*", triggerColor = sf::Color::Magenta; }
    void Trigger(std::shared_ptr<Field> field) override;
};