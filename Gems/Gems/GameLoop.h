#pragma once

class GameLoop : public Menu {
private:
    bool secondClick = false;
    bool dropped = false;
    bool bonusSpawned = false;
    bool deleted = false;
    bool bonusTriggered = false;
    bool hasFocus = true;
    unsigned gem1X;
    unsigned gem1Y;
    unsigned gem2X;
    unsigned gem2Y;
    std::shared_ptr <sf::RenderWindow> window;
    std::shared_ptr <Field> field;
    std::shared_ptr <Bonus> bonus;

    void CheckEvents();
    void TriggerBonus();
    void ProcessField();
    void SpawnBonus();
    void MouseControls();
public:
    GameLoop();
    ~GameLoop() {
        window.reset();
        field.reset();
        bonus.reset();
    }
    void Start();
};