// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void numToWords (int x) {
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
