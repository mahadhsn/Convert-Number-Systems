// This is a program that gets the input from the user
// Created by: Mahad Hassan 400437492
// Created on: 2024-11-7 

#include <stdio.h>
#include <string.h>
int get_input(char *input) { // get_input() gets the input from the user
    if (scanf("%s", input) == EOF) { // if the input is EOF, return 0
        strcpy(input, "EOF"); // copy "EOF" to the input
        return 0;
    }
    return 1; // return 1 if the input is not EOF
}