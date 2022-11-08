#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "shovein.h"

int main(int argc, char* argv[]) {
    int fd;

    if ((fd = socket(AF_CP, SOCK_RAW, 0)) < 0) {
        perror("Catnet socket creation failed");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
