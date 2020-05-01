#include <SFML/Graphics.hpp>
#include "Main.h"
#include "Menu.h"
#include "Font.h"

int main(void) {

    setlocale(LC_ALL, "Russian");

    srand((unsigned)time(0));   //random gems' colors generation

    Menu menu;     //console menu

    menu.Start();

    return 0;
}