#include <SFML/Graphics.hpp>
#include "Main.h"

int main(void) {

    setlocale(LC_ALL, "Russian");

    srand((unsigned)time(0));   //random gems' colors generation

    Help();     //console menu

    GameLoop();     //game window itself

    return 0;
}