// This is a program that converts an inputted value into a chosen base value
// Created by: Mahad Hassan 400437492
// Created on: 2024-11-7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "get_input.h"
#include "help_usage.h"


int main(int argc, char *argv[]) { // main function that converts an inputted value into a chosen base value
    int base = DEFAULT_BASE;
    long start = 0, finish = 0, num; // instantiate values
    int mode = 0;

    define_values(argc, argv, &base, &start, &finish, &mode); // define the values of the base, start, finish, and mode

    char input[100]; // Buffer to store input

    call_usage_help(mode, valid_syntax(argc, argv)); // call the usage/help functions
    
    conversion(mode, num, base, start, finish, input); // convert the numbers based on the mode by calling the conversion function

    return 0; // return 0 if the program runs successfully
}