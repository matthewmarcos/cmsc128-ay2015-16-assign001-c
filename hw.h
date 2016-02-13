// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void numToWords (int x) {
    int i, j, numHolderLevels, length, thunder = 0, remainingLength;
    char str[225];
    char number[] = "";
    char *ones[] = {
        "zero", "one",
        "two", "three",
        "four", "five",
        "six", "seven",
        "eight", "nine"
    };
    char *teens[] = { "",
        "ten", "eleven",
        "twelve", "thirteen",
        "fourteen", "fifteen",
        "sixteen", "seventeen",
        "eighteen", "nineteen",
    };
    char *tens[] = {
        "", "",
        "twenty", "thirty",
        "forty", "fifty",
        "sixty", "seventy",
        "eighty", "ninety"
    };
    char *thunders[] = {"", "thousand", "million"};
    sprintf(str, "%d", x); //Convert integer to characters
    length = (int)strlen(str);
    printf("Excess: %d\n", length%3);
    printf("Thunder: %s\n", thunders[(length-1)/3]);

    i = 0;
    while(str[i] != 0) {


        i++;
    }
}
