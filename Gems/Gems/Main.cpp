#include "Main.h"

int main(void) {

    setlocale(LC_ALL, "Russian");

    srand((unsigned)time(0));   //random gems' colors generation

    Help();

    GameLoop();

    return 0;
}