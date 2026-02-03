#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[16];  // small stack buffer

    // Unsafe copy — no bounds checking
    strcpy(buffer, input);

    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    vulnerable_function(argv[1]);
    return 0;
}

