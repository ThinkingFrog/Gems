#include <iostream>
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
        return cHelp;
    if (command == "/play")
        return cPlay;
    if (command == "/setup")
        return cSetup;
    return cWrong;
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

        case cHelp:
            switch (LocaleType(language)) {
            case lEn:
                std::cout << "Here are all available commands:" << std::endl << "/help - get a list of all available commands" << std::endl << "/setup - choose window resolution and field size" << std::endl
                    << "/play - start the game" << std::endl;
                break;

            case lRu:
                std::cout << "Все доступные комманды:" << std::endl << "/help - получить список всех доступных комманд" << std::endl << "/setup - настроить разрешения окна и размеры поля" << std::endl
                    << "/play - начать играть" << std::endl;
                break;
            }
            break;

        case cPlay:
            return;
            break;

        case cSetup:
            Setup();
            break;

        case cWrong:
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