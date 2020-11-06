// License: CC BY-NC-SA 4.0
/*
 * Random.h
 *
 * Library based on stdlib.h rand() function.
 *
 * Written by AlexeyFilich
 * 15 oct 2020
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Returns a random integer from a to b
int aRandInt(int a, int b) {
    static bool seed = true;
    if (seed) { // Seed the random number generator if it was not
        srand(time(0));
        seed = false;
    }
    return rand() % (b + 1 - a) + a; // Change the 'range' to [0; b - a] and add a to [a; b]
}

#endif
