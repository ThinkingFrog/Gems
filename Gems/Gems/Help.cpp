﻿#include <iostream>
#include <string>
#include "Main.h"

std::string language = "en";

language_code LocaleType(std::string language) {
    if (language == "en")
        return lEn;
    if (language == "ru")
        return lRu;
}

command_code CommandType(std::string command) {
    if (command == "/help")
        return cmHelp;
    if (command == "/play")
        return cmPlay;
    if (command == "/setup")
        return cmSetup;
    if (command == "/exit")
        return cmExit;
    return cmWrong;
}

void Help(void) {

    do {
        if (language != "en" && language != "ru")
            std::cout << "Wrong language typed" << std::endl;
        std::cout << "Choose language (ru/en): ";
        std::cin >> language;
    } while (language != "en" && language != "ru");

    std::string command;

    switch (LocaleType(language)) {

    case lEn:
        std::cout << "You can now operate game menu. To start playing type /play, for other commands type /help" << std::endl;
        break;

    case lRu:
        std::cout << "Вам доступно окно игрового меню. Чтобы начать играть введите /play, для дополнительных команд введите /help" << std::endl;
        break;
    }

    while (true) {

        switch (LocaleType(language)) {
        case lEn:
            std::cout << "Input: ";
            break;

        case lRu:
            std::cout << "Ввод: ";
            break;
        }

        std::cin >> command;

        switch (CommandType(command)) {

        case cmHelp:
            switch (LocaleType(language)) {
            case lEn:
                std::cout << "Here are all available commands:" << std::endl << "/help - get a list of all available commands" << std::endl << "/setup - choose window resolution and field size" << std::endl
                    << "/play - start the game" << std::endl << "/exit - close menu and quit" << std::endl;
                break;

            case lRu:
                std::cout << "Все доступные комманды:" << std::endl << "/help - получить список всех доступных комманд" << std::endl << "/setup - настроить разрешения окна и размеры поля" << std::endl
                    << "/play - начать играть" << std::endl << "/exit - закрыть меню и выйти" << std::endl;
                break;
            }
            break;

        case cmPlay:
            GameLoop();
            break;

        case cmSetup:
            Setup();
            break;

        case cmExit:
            std::exit(0);
            break;

        case cmWrong:
            switch (LocaleType(language)) {
            case lEn:
                std::cout << "No such command found" << std::endl;
                break;

            case lRu:
                std::cout << "Команда не найдена" << std::endl;
                break;
            }
            break;
        }
    }
}