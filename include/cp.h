#ifndef _CP_CP_H_
#define _CP_CP_H_

#ifndef BUILDING_AS_MODULE
#include <stdint.h>
#else
#include <linux/net.h>
#endif

/* Check if we need to update the below AF and PF values,
 * but this code will only ever compile if building in
 * relation to the non-UAPI headers, so we only check
 * when building a module.
 * Doesn't matter much anyways, this check doesn't
 * need to be preformed when building userspace code.
 */
#ifdef BUILDING_AS_MODULE
#if AF_MAX > 47
#error New address family defined, please update this file.
#endif /* AF_MAX > 47 */
#endif /* BUILDING_AS_MODULE*/

#ifndef _UAPI_LINUX_SOCKET_H
#define AF_CP 46
#define PF_CP 46
#endif /* _UAPI_LINUX_SOCKET_H */

#define NF_IX 0
#define LF_ETHERNET 0

/** Standard CP protocols. */
enum {
    /** Internetworking-Xchange protocol. */
    CPPROTO_IX = 0,
#define CPPROTO_IX CPPROTO_IX
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
/** Structure representing an IX address. */
static struct ix_addr {
    /** Network layer protocol, IX in this case. */
    uint8_t net_proto : 1;
    /** Link layer protocol, probably Ethernet. */
    uint8_t link_proto : 3;
    /** Link layer address, probably Ethernet. */
    uint8_t link_addr[6];
    /** Subnet identifier. */
    uint16_t subnet;
} ix_addr;

/** Structure presenting an IX socket address. */
static struct sockaddr_ix {
    /* Address family. */
    unsigned short family;
    /** UNIX port. */
    uint16_t port;
    /** IX address. */
    struct ix_addr addr;

    /* Pad to size of `struct sockaddr'. */
    /* unsigned char __pad[__SOCK_SIZE__ - sizeof(short int) -
        sizeof(unsigned short int) - sizeof(struct in_addr)]; */
} sockaddr_ix;
#pragma GCC diagnostic pop

#endif /* _CP_CP_H_ */
