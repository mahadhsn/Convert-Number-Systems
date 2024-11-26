// This is a program that prints help and usage messages
// Created by: Mahad Hassan 400437492
// Created on: 2024-11-7 

#include <stdio.h>
#include <stdlib.h>

void print_help() { // print_help() prints the help message to stdout
    char help[] = 
    "convert: v1.0.0\n"
    "convert is a program that converts numbers between different bases.\n"
    "Usage:\n"
    "\t convert [-b BASE] [-r START FINISH]\n"
    "\t 1 < BASE < 37\n"
    "\t START and FINISH are long integers\n"
    "\n"
    "Example:\n"
    "\t convert -b 2 -r 0 2\n"
    "\n"
    "\t convert\n"
    "\t 156\n"
    "\n"
    "\t convert -b 20\n"
    "\t 163578\n"
    "\n"
    "Example 1 output:\n"
    "\t 0 1 10\n"
    "\n"
    "Arguments:\n"
    "\t -b BASE: The base to convert to. Must be between 2 and 36.\n"
    "\t -r START FINISH: The range of numbers to convert.\n"
    "\t --help: Display this help message.\n";
    printf("%s", help);
}

void print_usage() { // print_usage() prints the usage message to stderr
    char usage[] =
    "Usage: convert [-b BASE] [-r START FINISH]\n"
    "       1 < BASE < 37\n"
    "       START and FINISH are long integers\n";
    fprintf(stderr,"%s", usage);
}

void call_usage_help(int mode, int valid) {
    if (mode == -1 || valid) { // if the mode is -1 (invalid syntax) or invalid syntax, print the usage message and exit 1
        print_usage();
        exit(1);
    }

    if (mode == 1) { // if the mode is 1 (help mode), print the help message
        print_help();
        exit(0);
    }
}