#pragma once
#include "Bonus.h"

/**
*Painter bonus class derived from abstract Bonus class
*
*Painter paints 2 other random cells in radius of [2, 3] cells into self color
*/
class Painter : public Bonus {
private:
    /**
    *Bonus will paint [paintedAmount] random gems in radius from 2 to [paintedRadius] both including
    */
    unsigned paintedAmount = 2, paintedRadius = 3;
public:
    /**
    *Constructor specifing bonus type, trigger message and its color
    */
    Painter();

    /**
    *Overriden trigger() method
    *
    *Painter paints 2 other random cells in radius of [2, 3] cells into self color
    *
    *@param field Shared pointer to playfield Field object. Needed to interact with gemsMatrix
    */
    void Trigger(std::shared_ptr<Field> field) override;
};