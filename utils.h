//
// Created by Paul Contreras on 13/02/25.
//


// This util helper is used to determine the OS name
#pragma once
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static const char *os_name() {
#if defined(_WIN32) || defined(_WIN64)
    return "Windows";
#elif defined(__APPLE__) || defined(__MACH__)
    return "macOS";
#elif defined(__linux__) || defined(linux) || defined(__linux)
    return "Linux";
#elif defined(__unix__) || defined(__unix) || defined(unix)
    return "Unix";
#else
    return "Unknown";
#endif
}

static void help() {
    printf("Use: copy [-r for recursive copying] <source> <destination>\n");
}

// Copy command implementation
static void copy(const char *source, const char *destination) {
    const int in = open(source, O_RDONLY);
    if (in == -1) {
        perror("Error opening source file");
        exit(1);
    }

    const int out = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror("Error opening destination file");
        close(in);
        exit(1);
    }

    char buffer[4096];
    ssize_t bytes;
    while ((bytes = read(in, buffer, sizeof(buffer))) > 0) {
        ssize_t written = 0;
        while (written < bytes) {
            const ssize_t result = write(out, buffer + written, bytes - written);
            if (result < 0) {
                perror("Error writing to destination file");
                close(in);
                close(out);
                exit(1);
            }
            written += result;
        }
    }

    if (bytes < 0) {
        perror("Error reading from source file");
    }

    close(in);
    close(out);
}