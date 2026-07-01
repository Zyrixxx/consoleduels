#include "../include/console_utils.hpp"

#include <iostream>
#include <limits>

#if defined(_WIN32)
#define NOMINMAX
#include <windows.h>
#endif

void clearScreen()
{
#if defined(_WIN32)
    if (const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); handle != INVALID_HANDLE_VALUE)
    {
        DWORD mode = 0;
        if (GetConsoleMode(handle, &mode))
        {
            SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        }
    }
#endif

    std::cout << "\033[2J\033[H" << std::flush;
}

void flushInputLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void resetInputAfterError()
{
    std::cin.clear();
    flushInputLine();
}

void handleInputError()
{
    resetInputAfterError();
    clearScreen();
}
