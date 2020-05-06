#include <iostream>
#include <string>
#include "Menu.h"
#include "GameLoop.h"

void Menu::Start() {

    StartupMessage();

    GameLoop gameLoop;

    while (true) {

        InputMessage();

        std::string command;
        std::cin >> command;

        switch (CommandType(command)) {

        case cmHelp:
            HelpMessage();
            break;

        case cmPlay:
            gameLoop.Start(*this);
            break;

        case cmSetup:
            Setup();
            break;

        case cmRules:
            RulesMessage();
            break;

        case cmLang:
            ChangeLang();
            break;

        case cmExit:
            return;
            break;

        case cmWrong:
            WrongCommandMessage();
            break;
        }
    }
}