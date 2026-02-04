#include <stdio.h>
#include <string.h>

void vulnerable_function(const char *input) {
    char buffer[16];

    // Looks safe, but is subtly wrong
    // Ensure null-termination in all cases
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    // Assumes buffer is always null-terminated
    printf("Input: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    vulnerable_function(argv[1]);
    return 0;
}

