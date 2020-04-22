#include <crtdbg.h>
#include <SFML/Graphics.hpp>
#include "Main.h"

int main(void) {

    setlocale(LC_ALL, "Russian");

    srand((unsigned)time(0));   //random gems' colors generation

    Help();     //console menu

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
    return 0;
}