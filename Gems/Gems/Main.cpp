#include "Main.h"

int main(void) {

    srand((unsigned)time(0));   //random gems' colors generation

    Help();

    GameLoop();

    return 0;
}