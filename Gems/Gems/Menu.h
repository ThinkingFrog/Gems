#pragma once

enum language_code {
    lEn,
    lRu,
    lCount
};

enum command_code {
    cmHelp,
    cmPlay,
    cmSetup,
    cmRules,
    cmLang,
    cmExit,
    cmCount,
    cmWrong
};

class Menu {
private:
    std::string language;
    unsigned fieldWidth, fieldHeight, userResolutionWidth, userResolutionHeight;    
    language_code LocaleType(std::string language);
    command_code CommandType(std::string command);
    void Setup();
    void StartupMessage();
    void InputMessage();
    void HelpMessage();
    void WrongCommandMessage();
    void RulesMessage();
    void ChangeLang();
    void GameLoop();
public:
    Menu();
    void Start();
    ~Menu() {}
};