// License: CC BY-NC-SA 4.0
/*
 * Console.h
 *
 * Functions for work with console.
 *
 * Written by AlexeyFilich
 * 15 oct 2020
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#ifdef _WIN32

#include <windows.h>

// Get and return console buffer size
void aGetConsoleBufferSize(int * width, int * height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

#endif

#endif
