#pragma once

/**Enum used to manipulate console menu language*/
enum language_code {
    lEn,
    lRu,
    lCount
};

/**Enum used to manipulate console menu commands*/
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
    std::string language;   /**Menu text language*/
    unsigned fieldWidth, fieldHeight;   /**Field size in gems*/
    unsigned userResolutionWidth, userResolutionHeight;   /**Window resolution*/

    /**
    *Return type of locale for given string
    *
    *Used to print text in console in different languages using switch()
    */
    language_code LocaleType(std::string language);

    /**
    *Return type of command for given string
    *
    *Used to manipulate console menu using switch()
    */
    command_code CommandType(std::string command);

    /**
    *Launch /setup command module
    *
    *Can be used to set screen resolution and field size from inside menu between games
    */
    void Setup();

    /**
    *Message shown when menu starts
    */
    void StartupMessage();

    /**
    *Message shown when wait for input
    */
    void InputMessage();

    /**
    *Message shown when /help command activated
    */
    void HelpMessage();

    /**
    *Message shown when wrong command is typed
    */
    void WrongCommandMessage();

    /**
    Message shown when /rules command activated
    */
    void RulesMessage();

    /**
    *Change language menu option
    */
    void ChangeLang();
public:
    Menu();
    void Start();
    ~Menu() {}
    unsigned GetFieldWidth();
    unsigned GetFieldHeight();
    unsigned GetUserResolutionWidth();
    unsigned GetUserResolutionHeight();
};