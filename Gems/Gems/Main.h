#pragma once

#define BONUS_CHANCE 100
#define BONUS_COUNT 2

enum language_code {
    lEn,
    lRu,
    lCount
};

enum command_code {
    cmHelp,
    cmPlay,
    cmSetup,
    cmExit,
    cmCount,
    cmWrong
};

extern unsigned fieldWidth, fieldHeight, userResolutionWidth, userResolutionHeight;
extern std::string language;

language_code LocaleType(std::string language);
command_code CommandType(std::string command);
void GameLoop(void);
void Setup(void);
void Help(void);