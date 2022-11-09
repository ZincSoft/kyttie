#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <cp.h>

int main(int argc, char* argv[]) {
    struct sockaddr_ix addr;
    int fd;

    if ((fd = socket(AF_CP, SOCK_RAW, CPPROTO_IX)) < 0) {
        perror("Catnet socket creation failed");

        return EXIT_FAILURE;
    }

    addr.family = AF_CP;
    addr.port = 8000;
    addr.addr.net_proto = NF_IX;
    addr.addr.link_proto = LF_ETHERNET;
    memcpy(addr.addr.link_addr, (uint8_t[8]) { 0x38, 0xf7, 0xcd, 0xc0, 0x45, 0x77 }, 8);
    addr.addr.subnet = 0x0000;

    if (sendto(fd, "foo", sizeof("foo"), 0, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("Catnet socket failed sendto");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
