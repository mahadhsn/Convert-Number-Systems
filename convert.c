// This is a program that converts an inputted value into a chosen base value
// Created by: Mahad Hassan 400437492
// Created on: 2024-11-7 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "convert.h"
#include "get_input.h"

int valid_syntax(int argc, char *argv[]) { // valid_syntax() checks if the syntax of the input is valid (return 0) or invalid (return 1)
    if (argc == 1) {  // base case
        return 0;
    }
    else if (argc == 2 && (strcmp(argv[1], "--help") == 0)) {  // for --help message
        return 0;
    }
    else if (argc == 3 && (strcmp(argv[1], "-b") == 0) && (is_digit(argv[2]) == 0)) { // for changing the base
        int base = atoi(argv[2]);
        if (base < MIN_BASE || base > MAX_BASE) { // if statement to check if the base is between 2 and MAX_BASE
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (argc == 4 && (strcmp(argv[1], "-r") == 0) && (is_digit(argv[2]) == 0) && (is_digit(argv[3]) == 0)) { // for changing the range
        return 0;
    }
    else if (argc == 5) {
        return 0;
    }
    else if (argc == 6  && (strcmp(argv[1], "-b") == 0) && (is_digit(argv[2]) == 0) && (strcmp(argv[3], "-r") == 0) && (is_digit(argv[4]) == 0) && (is_digit(argv[5]) == 0)) { // for changing the base and range
        int base = atoi(argv[2]);
        
        if (base < MIN_BASE || base > MAX_BASE) { // if statement to check if the base is between 2 and MAX_BASE
            return 1;
        }
        else {
            return 0;
        }
    }
    else { 
        return 1; // return 1 if the syntax is invalid
    }
}

int check_mode(int argc, char *argv[]) { // check_mode() checks what mode the program is in
    if (valid_syntax(argc, argv) == 0) { // if the syntax is valid
        if (argc == 1) { // for base case
            return 0;
        }

        else if (argc == 2) { // for --help message
            return 1;
        }

        else if (argc == 3) { // for changing the base
            return 2;
        }

        else if (argc == 4) { // for changing the range
            return 3;
        }

        else if (argc == 6) { // for changing the base and range
            return 5;
        }
    }
    else { 
        return -1; 
    }                   // return -1 if the syntax is invalid
    return -1;
}

void define_values(int argc, char *argv[], int *base, long *start, long *finish, int *mode) { // define_values() defines the values of the base, start, finish, and mode using pointers
    if (check_mode(argc, argv) == 0) { // set the mode to 0 (base case for hex)
        *mode = 0;
    }
    
    if (check_mode(argc, argv) == 1) {
        *mode = 1; // set mode to 1 (--help message)
    }
    else if (check_mode(argc, argv) == 2) {
        *base = atoi(argv[2]);
        *mode = 2; // set mode to 2 (base has been changed so change the base)
    }
    else if (check_mode(argc, argv) == 3) {
        *start = atol(argv[2]);
        *finish = atol(argv[3]);
        *mode = 3; // set mode to 3 (range has been changed so must iterate through it)
    }
    else if (check_mode(argc, argv) == 5) {
        *base = atoi(argv[2]);
        *start = atol(argv[4]);
        *finish = atol(argv[5]);
        *mode = 5; // set mode to 5 (both base and range have been changed)
    }
    else if (check_mode(argc, argv) == -1) {
        *mode = -1; // set mode to -1 (invalid syntax)
    }
}

void convert_numbers(long num, int base) { // convert_numbers() converts a number to a different base
    if (num < 0) { // if the number is negative add a negative sign and make the number positive for conversion
        printf("-");
        num = -num;
    }
    if (num >= base) { // if the number is greater than or equal to the base, recursively call convert_numbers() with the number divided by the base
        convert_numbers(num / base, base);
    }
    int remainder = num % base; 
    if (remainder < 10) { // if the remainder is less than 10, print the remainder
        printf("%d", remainder);
    }
    else {
        printf("%c", 'A' + remainder - 10); // if the remainder is greater than or equal to 10, print the corresponding character
    }
}

int is_digit(const char *str) { // is_digit() checks if an inputted string is a digit
    if (*str == '-') { // ignore the negative sign
        str++;
    }
    while (*str) { // iterate through the string
        if (*str < '0' || *str > '9') { // if the character is not a digit
            return 1; // return 1
        }
        str++;
    }
    return 0; // return 0 if all characters are digits
}

void conversion(int mode, long num, int base, long start, long finish, char *input) { // conversion() converts the numbers based on the mode
    if (mode == 3 || mode == 5) {  // if the mode is 3 (range mode) or 5 (both base and range have been changed) iterate through the range
        for (long i = start; i <= finish; i++) {
            convert_numbers(i, base);
            printf("\n");
        }
    }
    else {
        get_input(input);  // get the initial input and check for EOF
        while (strcmp(input, "EOF") != 0) { // while input is not "EOF"
            if (is_digit(input) == 0) { // if the input is a digit
                num = atol(input); // convert the string input to a long int
                convert_numbers(num, base); // convert the number to the base
                printf("\n");
            } else {
                fprintf(stderr, "Error: Non-long-int token encountered\n"); // if the input is not a digit, print an error message and exit 1
                exit(1);
            }
            if (!get_input(input)) { // get the next input and check for EOF
                break;
            }
        }
    }
}