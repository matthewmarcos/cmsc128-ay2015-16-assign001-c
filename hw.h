// Created by: Joseph Matthew R. Marcos
// CMSC 128 AB-5L
// Programming Assignment 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void numToWords (int x) {
    char str[225];
    sprintf(str, "%d", x);

    printf("%s\n", str);
}
