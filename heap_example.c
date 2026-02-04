#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = malloc(16);  // allocate 16 bytes

    if (!buffer) {
        return 1;
    }

    // Unsafe write — exceeds allocated memory
    //strcpy(buffer, "This string is definitely longer than 16 bytes");
    strncpy(buffer, "This string is definitely longer than 16 bytes", len(buffer) - 1);

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}

