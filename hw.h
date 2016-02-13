// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void numToWords (int x) {
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
    char *thunders[] = {"hundred", "thousand", "million"};

    sprintf(str, "%d", x); //Convert integer to characters

    // printf("%s\n", str);
    int length = ;
    int i, j;
    for(i = strlen(str) ; i >=0 ; i--) {
        printf("%c\n", str[i]);
    }

}
