#include <iostream>
#include "Main.h"

unsigned fieldWidth = 10, fieldHeight = 10; //Amount of gems in row and in column
unsigned userResolutionWidth = 800, userResolutionHeight = 600;    //Window resolution

void Setup(std::string language) {

    switch (LocaleType(language)) {
    case lEn:
        std::cout << "Input window resolution (by default 800 600): ";
        std::cin >> userResolutionWidth >> userResolutionHeight;

        std::cout << "Input field size (by default 10 10): ";
        std::cin >> fieldWidth >> fieldHeight;
        break;

    case lRu:
        std::cout << "Введите разрешение окна (по умолчанию 800 600): ";
        std::cin >> userResolutionWidth >> userResolutionHeight;

        std::cout << "Введите размеры поля (по умолчанию 10 10): ";
        std::cin >> fieldWidth >> fieldHeight;
        break;
    }
}