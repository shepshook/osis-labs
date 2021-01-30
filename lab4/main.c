#include <stdio.h>
#include <string.h>
#include "algo.h"

char* help_message = "Usage: \n  -h \t\tPrint this message.\n  -l \t\tList all running processes.\n  -p <pid> \tGet info about process with specified PID.\n";

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        printf("%s", help_message);
        return 0;
    }

    if (!strcmp(argv[1], "-h")) {
        printf("%s", help_message);
    }
    else if (!strcmp(argv[1], "-l")) {
        list_processes();
    }
    else if (!strcmp(argv[1], "-p") && argc == 3) {
        process_info(argv[2]);
    }
    else {
        printf("Wrong input!\n");
    }

    return 0;
}
