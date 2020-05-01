#include <iostream>
#include <string>
#include "Menu.h"
#include "Main.h"

Menu::Menu() {
    fieldWidth = 10, fieldHeight = 10;
    userResolutionWidth = 800, userResolutionHeight = 600;
    
    language = "en";
    do {
        if (language != "en" && language != "ru")
            std::cout << "Wrong language typed" << std::endl;
        std::cout << "Choose language (ru/en): ";
        std::cin >> language;
    } while (language != "en" && language != "ru");
}

language_code Menu::LocaleType(std::string language) {
    if (language == "en")
        return lEn;
    if (language == "ru")
        return lRu;
}

command_code Menu::CommandType(std::string command) {
    if (command == "/help")
        return cmHelp;
    if (command == "/play")
        return cmPlay;
    if (command == "/setup")
        return cmSetup;
    if (command == "/exit")
        return cmExit;
    if (command == "/rules")
        return cmRules;
    if (command == "/lang")
        return cmLang;
    return cmWrong;
}

void Menu::Setup() {
    switch (LocaleType(language)) {
    case lEn:
        std::cout << "Input window resolution (by default 800 600): ";
        std::cin >> userResolutionWidth >> userResolutionHeight;

        do {
            if (fieldWidth <= BONUS_SPAWN_RADIUS || fieldHeight <= BONUS_SPAWN_RADIUS)
                std::cout << "Field too small, try bigger values";
            std::cout << "Input field size (by default 10 10): ";
            std::cin >> fieldWidth >> fieldHeight;
        } while (fieldWidth <= BONUS_SPAWN_RADIUS || fieldHeight <= BONUS_SPAWN_RADIUS);
        break;

    case lRu:
        std::cout << "Введите разрешение окна (по умолчанию 800 600): ";
        std::cin >> userResolutionWidth >> userResolutionHeight;

        std::cout << "Введите размеры поля (по умолчанию 10 10): ";
        std::cin >> fieldWidth >> fieldHeight;
        break;
    }
}

void Menu::StartupMessage() {
    switch (LocaleType(language)) {

    case lEn:
        std::cout << "You can now operate game menu. To start playing type /play, for other commands type /help" << std::endl;
        break;

    case lRu:
        std::cout << "Вам доступно окно игрового меню. Чтобы начать играть введите /play, для дополнительных команд введите /help" << std::endl;
        break;
    }
}

void Menu::InputMessage() {
    switch (LocaleType(language)) {
    case lEn:
        std::cout << "Input: ";
        break;

    case lRu:
        std::cout << "Ввод: ";
        break;
    }
}

void Menu::HelpMessage() {
    switch (LocaleType(language)) {
    case lEn:
        std::cout << "Here are all available commands:" << std::endl << "/help - get a list of all available commands" << std::endl << "/rules - show game rules" << std::endl <<
            "/setup - choose window resolution and field size" << std::endl << "/lang - change language" << std::endl << "/play - start the game" << std::endl << "/exit - close menu and quit" << std::endl;
        break;

    case lRu:
        std::cout << "Все доступные комманды:" << std::endl << "/help - получить список всех доступных комманд" << std::endl << "/rules - показать правила" << std::endl 
            << "/setup - настроить разрешения окна и размеры поля" << std::endl << "/lang - выбрать язык" << std::endl << "/play - начать играть" << std::endl << "/exit - закрыть меню и выйти" << std::endl;
        break;
    }
}

void Menu::WrongCommandMessage() {
    switch (LocaleType(language)) {
    case lEn:
        std::cout << "No such command found" << std::endl;
        break;

    case lRu:
        std::cout << "Команда не найдена" << std::endl;
        break;
    }
}

void Menu::RulesMessage() {
    switch (LocaleType(language)) {
    case lEn:
        std::cout << "Main goal is to get three or more matching gems together" << std::endl << "Gems only count matching if they have the same color and are neighbours from left, right, up or down"
            << std::endl << "When combination appers on the field, it deletes and all gems above it drop down on free cells" << std::endl <<
            "When there are no gems that can drop down, all remaining free cells get filled at once with random colors" << std::endl << "You can control using your mouse" << std::endl <<
            "To choose gem you need to press on it with left mouse button" << std::endl << "Selected gem is highlited with yellow outline. To cancel selection press right mouse button anywhere"
            << std::endl << "Selected gem can be swapped with any neighbour gem" << std::endl << "When combination deletes, there is a " << BONUS_CHANCE << "% chance for each deleted gem, that in "
            << BONUS_SPAWN_RADIUS << " cells radius will appear a random bonus" << std::endl << "There are two bonus types: Bomb and Painter" << std::endl 
            << "Bomb destroys its cell and 4 other random across all field" << std::endl << "Painter paints 2 random non-neighbour cells in radius of 3 in color of its cell" << std::endl
            << "Bonuses trigger immediately when they appear" << std::endl;
        break;

    case lRu:
        std::cout << "Главная задача - собрать три или более гема одинакового цвета рядом" << std::endl << "Учитываются соседние гемы только сверху, снизу, справа и слева"
            << std::endl << "Когда на поле появляется комбинация, она удаляется, и все гемы, находящиеся над ней, спускаются на свободные позиции" << std::endl <<
            "Когда больше нет гемов, которые могут спуститься вниз, все свободные места заполняются новыми случайных цветов" << std::endl << "Управление осуществляется мышкой" << std::endl <<
            "Чтобы выбрать гем, нажмите на него левой кнопкой мыши" << std::endl << "Когда гем выделен, он подсвечивается жёлтой обводкой. Чтобы отменить выделение, нажмите правой кнопкой мыши где угодно"
            << std::endl << "Когда гем выделен, его можно поменять местами с любым соседним недиагональным гемом" << std::endl << "При уничтожение комбинации есть шанс "
            << BONUS_CHANCE << "% за каждый гем в комибнации, что в окрестности " << BONUS_SPAWN_RADIUS << " ячеек появится случайный бонус" << std::endl << "Бонусы есть двух видов: Бомба и Окрашиватель" 
            << std::endl << "Бомба - взрывает свою и ещё 4 случайные ячейки по всему полю" << std::endl << "Окрашиватель - окрашивает 2 случайные несоседние ячейки в радиусе 3 в цвет своей ячейки" <<std::endl
            << "Бонусы срабатывают сразу при появлении" << std::endl;
        break;
    }
}

void Menu::ChangeLang() {
    do {
        if (language != "en" && language != "ru")
            std::cout << "Wrong language typed" << std::endl;
        std::cout << "Choose language (ru/en): ";
        std::cin >> language;
    } while (language != "en" && language != "ru");
}