#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buffer[16];

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <texto>\n", argv[0]);
        return 1;
    }

    /* Intencionadamente inseguro: solo para laboratorio local. */
    strcpy(buffer, argv[1]);

    printf("Entrada: %s\n", buffer);
    return 0;
}
