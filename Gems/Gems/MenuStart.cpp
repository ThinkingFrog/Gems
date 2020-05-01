#include <iostream>
#include <string>
#include "Menu.h"
#include "GameLoop.h"

void Menu::Start() {

    StartupMessage();

    while (true) {

        InputMessage();

        std::string command;
        std::cin >> command;

        switch (CommandType(command)) {

        case cmHelp:
            HelpMessage();
            break;

        case cmPlay:
            GameLoop GameLoop();
            GameLoop.Start();
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