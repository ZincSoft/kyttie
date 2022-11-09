#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <cp.h>

int main(int argc, char* argv[]) {
    int fd;

    if ((fd = socket(AF_CP, SOCK_RAW, CPPROTO_IX)) < 0) {
        perror("Catnet socket creation failed");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
