convert: main.c convert.c get_input.c help_usage.c convert.h get_input.h help_usage.h
	gcc -o convert main.c convert.c get_input.c help_usage.c
ctest: main.c convert.c get_input.c help_usage.c convert.h get_input.h help_usage.h
	gcc -o ctest --coverage main.c convert.c get_input.c help_usage.c
