#include "utils.h"
#include <stdio.h>
#include <string.h>

int main(const int argc, char *argv[]) {
    if (argc < 3) {
        help();
        return 1;
    }
    // This is for the recursive copying
    // TODO -> Implement the recursive copying (in the part 2)
    int recursive = 0;
    if (argc == 4 && strcmp(argv[1], "-r") == 0) {
        recursive = 1;
    }

    const char *source = recursive ? argv[2] : argv[1];
    const char *destination = recursive ? argv[3] : argv[2];
    // Implement the copy function here
    copy(source, destination);
    return 0;
}
