// License: CC BY-NC-SA 4.0
/*
 * Interactions.h
 *
 * Functions for user interaction.
 *
 * Written by AlexeyFilich
 * 15 oct 2020
 */

#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Asks user for input until user inputs data in the correct way
void aScanCheck(const char * outfmt, const char * infmt, ...) {
    va_list args;
    va_start(args, infmt); // Get all arguments, passed to a function except format strings
    int argc = 0;
    for (int i = 0; i < strlen(infmt) - 1; i++) // For each but last character in infmt
        if (infmt[i] == '%' && infmt[i + 1] != '%') // If this and next character are '%d', '%c', etc. but not '%%' increment argument counter
            argc++;
    int ret; // vfscanf return code
    do {
        printf("%s", outfmt); // Print pre-input string
        ret = vfscanf(stdin, infmt, args); // Read data
        while (getchar() != '\n'); // Flush stdin
    } while (ret != argc); // Until we read all args correctly
    va_end(args);
}

// Show exit prompt
bool aQToExit() {
    printf("Press ENTER to start again ");
    if (getchar() != '\n') return true;
    return false;
}

#endif
