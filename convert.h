// This allows the user to include the functions in other programs
// Created by: Mahad Hassan 400437492
// Created on: 2024-11-7 

#define DEFAULT_BASE 16 // Default base is 16
#define MAX_BASE 36 // Maximum base is 36
#define MIN_BASE 2 // Minimum base is 2

int valid_syntax(int argc, char *argv[]);
int check_mode(int argc, char *argv[]);
void define_values(int argc, char *argv[], int *base, long *start, long *finish, int *mode);
void print_help();
void print_usage();
void convert_numbers(long num, int base);
int is_digit(const char *str);
void conversion(int mode, long num, int base, long start, long finish, char *input);
// define all the functions here