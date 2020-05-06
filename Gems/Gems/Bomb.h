#pragma once
#include "Bonus.h"

/**
*Bomb bonus class derived from abstract Bonus class
*
*Bomb explodes self and 4 other random cells
*/
class Bomb : public Bonus {
private:
    unsigned bombedAmount = 5;  /**Amount of cells bombed including self*/
public:
    /**
    *Constructor specifing bonus type, trigger message and its color
    */
    Bomb();

    /**
    *Overriden trigger() method
    *
    *Bomb explodes self and 4 other random cells
    *
    *@param field Shared pointer to playfield Field object. Needed to interact with gemsMatrix
    */
    void Trigger(std::shared_ptr<Field> field) override;
};