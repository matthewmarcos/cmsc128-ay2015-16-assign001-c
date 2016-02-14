// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void numbersDelimited(int num, char delimiter, int interval);
void wordsToNum(char str[]);
int findIndex(char mainArray[225][225], int limit, char searchFor[]);
void numToWords (int x);
int evaluateNumber(char mainArray[225][225], int size);
int __wordsToNum(char str[]);
void wordsToCurrency(char str[], char str2[]);

void wordsToCurrency(char str[], char str2[]) {
    printf("%d %s\n", __wordsToNum(str), str2);
    return;
}

void wordsToNum(char str[]) {
    printf("%d\n", __wordsToNum(str));
    return;
}

int __wordsToNum(char str[]) {
    // Accepts a number in
    // word form (from zero to 1
    // million) and returns it in
    // numerical form
    // Input must be in
    // lowercase
    int i = 0 , j = 0 , f = 0 , wordCount = 0 , answer = 0, index = 0;
    int tempHundreds, tempTens, tempOnes, tempIndex;
    const char s[2] = " ";
    char *token;
    char numbersDelimited[225][225], tempArray[225][225];
    // http://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    // get the first token
    token = strtok(str, s);
    //  walk through other tokens
    i = 0;
    while( token != NULL ) {
        // printf("%s\n", token);
        strcpy(numbersDelimited[i], token);
        i++;
        token = strtok(NULL, s);
    }
    wordCount = i;
    tempIndex = 0;
    index = findIndex(numbersDelimited, wordCount, "million"); //Kung may million
    if(index != -1) {
        // Evaluate
        for(i = tempIndex ; i < index ; i++) {
            strcpy(tempArray[i], numbersDelimited[i]);
        }
        tempIndex = i + 1;
        answer += evaluateNumber(tempArray, index) * 1000000;
    }
    index = findIndex(numbersDelimited, wordCount, "thousand"); //kung may thousand
    if(index != -1) {
        // Evaluate
        for(j = 0, i = tempIndex ; i < index ;j++, i++) {
            strcpy(tempArray[j], numbersDelimited[i]);
        }
        answer += evaluateNumber(tempArray, index-tempIndex) * 1000;
        tempIndex = i + 1;
    }
    //
    for(j = 0, i = tempIndex ; i < wordCount ;j++, i++) {
        strcpy(tempArray[j], numbersDelimited[i]);
    }
    answer += evaluateNumber(tempArray, wordCount-tempIndex);
    return answer;
}

int evaluateNumber(char mainArray[225][225], int size) {
    int i, j, k;
    int numHolder = 0, temp = 0;
    for(i = 0 ; i < size ; i++) {
        if(!strcmp(mainArray[i], "hundred") && i >= 1) { //May hundred
            // Determine if one to nine
            temp = 0;
            if(!strcmp(mainArray[i-1], "one")) {
                temp = 1;
            }
            else if(!strcmp(mainArray[i-1], "two")) {
                temp = 2;
            }
            else if(!strcmp(mainArray[i-1], "three")) {
                temp = 3;
            }
            else if(!strcmp(mainArray[i-1], "four")) {
                temp = 4;
            }
            else if(!strcmp(mainArray[i-1], "five")) {
                temp = 5;
            }
            else if(!strcmp(mainArray[i-1], "six")) {
                temp = 6;
            }
            else if(!strcmp(mainArray[i-1], "seven")) {
                temp = 7;
            }
            else if(!strcmp(mainArray[i-1], "eight")) {
                temp = 8;
            }
            else if(!strcmp(mainArray[i-1], "nine")) {
                temp = 9;
            }
            temp *= 100;
            numHolder += temp;
        }
        if(!strcmp(mainArray[i], "nineteen")) { //teens
            numHolder += 19;
        }
        else if(!strcmp(mainArray[i], "nineteen")) { //teens
            numHolder += 19;
        }
        else if(!strcmp(mainArray[i], "eighteen")) { //teens
            numHolder += 18;
        }
        else if(!strcmp(mainArray[i], "seventeen")) { //teens
            numHolder += 17;
        }
        else if(!strcmp(mainArray[i], "sixteen")) { //teens
            numHolder += 16;
        }
        else if(!strcmp(mainArray[i], "fifteen")) { //teens
            numHolder += 15;
        }
        else if(!strcmp(mainArray[i], "fourteen")) { //teens
            numHolder += 14;
        }
        else if(!strcmp(mainArray[i], "thirteen")) { //teens
            numHolder += 13;
        }
        else if(!strcmp(mainArray[i], "twelve")) { //teens
            numHolder += 12;
        }
        else if(!strcmp(mainArray[i], "eleven")) { //teens
            numHolder += 11;
        }
        else if(!strcmp(mainArray[i], "ten")) { //teens
            numHolder += 10;
        }
        else if(!strcmp(mainArray[i], "ninety")) { //tens... then ones in this else if
            numHolder += 90;
        }
        else if(!strcmp(mainArray[i], "eighty")) { //tens... then ones in this else if
            numHolder += 80;
        }
        else if(!strcmp(mainArray[i], "seventy")) { //tens... then ones in this else if
            numHolder += 70;
        }
        else if(!strcmp(mainArray[i], "sixty")) { //tens... then ones in this else if
            numHolder += 60;
        }
        else if(!strcmp(mainArray[i], "fifty")) { //tens... then ones in this else if
            numHolder += 50;
        }
        else if(!strcmp(mainArray[i], "forty")) { //tens... then ones in this else if
            numHolder += 40;
        }
        else if(!strcmp(mainArray[i], "thirty")) { //tens... then ones in this else if
            numHolder += 30;
        }
        else if(!strcmp(mainArray[i], "twenty")) { //tens... then ones in this else if
            numHolder += 20;
        }
        else if(i == size-1){
            temp = 0;
            if(!strcmp(mainArray[i], "one")) {
                temp = 1;
            }
            else if(!strcmp(mainArray[i], "two")) {
                temp = 2;
            }
            else if(!strcmp(mainArray[i], "three")) {
                temp = 3;
            }
            else if(!strcmp(mainArray[i], "four")) {
                temp = 4;
            }
            else if(!strcmp(mainArray[i], "five")) {
                temp = 5;
            }
            else if(!strcmp(mainArray[i], "six")) {
                temp = 6;
            }
            else if(!strcmp(mainArray[i], "seven")) {
                temp = 7;
            }
            else if(!strcmp(mainArray[i], "eight")) {
                temp = 8;
            }
            else if(!strcmp(mainArray[i], "nine")) {
                temp = 9;
            }
            numHolder += temp;
        }
    }
    // printf("numholder: %d\n", numHolder);

    return numHolder;
}

int findIndex(char mainArray[225][225], int limit, char searchFor[]) {
    int i, j;
    for(i = 0 ; i < limit ; i++) {
        if(!strcmp(mainArray[i], searchFor)) {
            return i;
        }
    }

    return -1;
}

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
        printf("%s\n", str);
        return;
    }
    printf("%s\n", number);

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

    printf("%s\n", number);
}
