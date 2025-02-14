#include "utils.h"
#include <stdio.h>
#include <string.h>

int main(const int argc, char *argv[]) {
    if (argc < 3) {
        help();
        return 1;
    }
    int recursive = 0;
    if (argc == 4 && strcmp(argv[1], "-r") == 0) {
        recursive = 1;
    }

    char *source = recursive ? argv[2] : argv[1];
    char *destination = recursive ? argv[3] : argv[2];

    // Print the source and destination for debugging
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
