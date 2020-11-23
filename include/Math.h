// License: CC BY-NC-SA 4.0
/*
 * Math.h
 *
 * My implementation of some mathematical functions.
 *
 * Written by AlexeyFilich
 * 15 oct 2020
 */

#ifndef MATH_H
#define MATH_H

#include <stdbool.h>
#include <stdio.h>

// x ^ n
float aPow(float x, int n) {
    if (n == 0) // x^0 = 1
        return 1;
    float temp = aPow(x, n / 2); // Calculate the half-power
    if (n % 2 == 0) // If power is even
        return temp * temp; // Return half-power squared
    else { // If odd
        if (n > 0)
            return temp * temp * x;
        else
            return temp * temp / x;
    }
}

// Print integer as binary
void aPrintBinary(int value, int prec, bool whitespace) {
    int mask = 1 << (prec - 1); // Create mask '1000...'
    for (int i = 0; i < prec; i++) {
        putchar(mask & value ? '1' : '0'); // If ith bit of value is one, print one
        value <<= 1; // Shift value 1 right
        if (i % 8 == 0 && whitespace && i != prec - 1) // Print ' ' every 8 digits
            putchar(' ');
    }
}

#endif
