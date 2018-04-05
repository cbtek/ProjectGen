/*
    ConsoleUtils.h
    

*/
#pragma once

#include "UtilityCommon.hpp"

#if defined (_WIN32) || defined (_WIN64)
    #define WINDOWS

    #include <windows.h>
    #include <conio.h>
#elif defined (__APPLE__) || defined (__MACH__) || defined (__unix__)
    #define UNIX
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <termios.h>
#endif

BEG_NAMESPACE_CBTEK_UTILITY
#if defined __WIN32
    enum ConsoleColors
    {
        Black = 0,
        Red = 12,
        Green = 2,
        Jaune = 14,
        Blue = 9,
        Magenta = 13,
        Cyan = 11,
        White = 15
    };
#elif defined UNIX
    enum ConsoleColors
    {
        Black = 30,
        Red = 31,
        Green = 32,
        Jaune = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37
    };
#endif

class ConsoleUtils 
{
public:
    /**
     * @brief getKeyCharacter
     * @return
     */
    static char getKeyCharacter();

    /**
     * @brief setConsoleColor
     * @param text_color
     * @param foreground_color
     */
    static void setConsoleColor(ConsoleColors text_color,
                                ConsoleColors foreground_color);
    /**
     * @brief clearScreen
     */
    static void clearScreen();

    /**
     * @brief moveCursor
     * @param row
     * @param column
     */
    static void moveCursor(int row, int column);

#ifdef UNIX
    static termios old_termios, new_termios;

    /* Initialize new_termios terminal i/o settings */
    static void initTermios(int echo);

    /* Restore old terminal i/o settings */
    static void resetTermios();

    /* Read 1 character - echo defines echo mode */
    static char getch_(int echo);

    /* Read 1 character without echo */
    static char getch(void);

    /* Read 1 character with echo */
    static char getche(void);
#endif
};
END_NAMESPACE_CBTEK_UTILITY
