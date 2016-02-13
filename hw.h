// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void numbersDelimited(int num, char delimiter, int interval) {
    // Accepts three arguments:
    // the first is the number from
    // zero to 1 miliion, the
    // second is the delimiter to
    // be used (single character
    // only) and third, the
    // number of jumps when
    // the delimiter will appear
    // (from right most going to
    // left most digit)
    char number[225];
    char str[225];
    int excess = 0, i = 0 , j = 0 , intervalCount = 1;
    // Initialize the variables
    sprintf(str, "%d", num);
    int length = (int)strlen(str); //length
    excess = length%interval;

    if(length <= interval) {
        printf("Output: %s\n", str);
        return;
    }
    printf("Output: %s\n", number);

    i = 0; j = 0;
    if(excess > 0) { //print the ones excess if you group numbers by interval
        for(j = 0 ; j < excess ; j++, i++) {
            putchar(str[j]);
        }
        putchar(delimiter);
        i++;
    }

    for(; j < length ; j++, i++) {
        putchar(str[j]);
        if(intervalCount == interval && (int)strlen(str + j) > 1) {
            i++;
            intervalCount = 1;
            continue;
        }
        intervalCount++;
    }

    putchar('\n');

    return;

}


void numToWords (int x) {
    // Accepts a whole number
    // from zero (0) to 1 million
    // (1000000; without commas
    // for example: 1,000,000)
    // and prints on screen the
    // number in word form

    if(x == 0) {
        printf("zero\n");
        return;
    }
    int i, j, y, numHolderLevels, length, thunder = 0, remainingLength, excess;
    char str[225], tempString[225];
    char number[225];
    char *ones[] = {
        "", "one ",
        "two ", "three ",
        "four ", "five ",
        "six ", "seven ",
        "eight ", "nine "
    };
    char *teens[] = {
        "ten ", "eleven ",
        "twelve ", "thirteen ",
        "fourteen ", "fifteen ",
        "sixteen ", "seventeen ",
        "eighteen ", "nineteen ",
    };
    char *tens[] = {
        "", "",
        "twenty ", "thirty ",
        "forty ", "fifty ",
        "sixty ", "seventy ",
        "eighty ", "ninety "
    };
    char *thunders[] = {"", "thousand ", "million "};
    char hundred[9];
    strcpy(hundred, "hundred ");
    strcpy(number, "");
    sprintf(str, "%d", x); //Convert integer to characters
    length = (int)strlen(str);
    excess = length%3;
    thunder = (length-1)/3;
    int gotExcess = 0; //Did not get the excess
    i = 0;
    while(thunder >= 0) {
        j = 0;
        strcpy(tempString, "000");
        char *currentLetter = str + i;
        if(!gotExcess && excess != 0) { //Di pa nakuka ang kaltas
            for(j = excess-1, y = 2 ; j >= 0; j--, i++, y--) {
                tempString[y] = currentLetter[j];
            }
            printf("TempString: %s\n", tempString);

            //Analyze tempString

            if(tempString[0] > '0') { //hundreds
                strcat(number, ones[tempString[0]-'0']);
                strcat(number, hundred);
            }
            if(tempString[1] > '1') {
                strcat(number, tens[tempString[1]-'0']);
            }
            if(tempString[1] == '1') {
                strcat(number, teens[tempString[2]-'0']);
            }
            else if(tempString[2] > '0') {
                strcat(number, ones[tempString[2]-'0']);
            }

            strcat(number, thunders[thunder]);
            gotExcess = 1;
            thunder--;
            continue;
        }
        else {
            for(int y = 0 ; y < 3 ; y++, i++) {
                tempString[y] = currentLetter[y];
            }

            if(tempString[0] > '0') { //hundreds
                strcat(number, ones[tempString[0]-'0']);
                strcat(number, hundred);
            }
            if(tempString[1] > '1') {
                strcat(number, tens[tempString[1]-'0']);
            }
            if(tempString[1] == '1') {
                strcat(number, teens[tempString[2]-'0']);
            }
            else if(tempString[2] > '0') {
                strcat(number, ones[tempString[2]-'0']);
            }

            strcat(number, thunders[thunder]);
            thunder--;
        }
    }


    printf("Input: %d\n", x);
    printf("Output: %s\n", number);
}
