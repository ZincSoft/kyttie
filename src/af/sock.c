#include <net/sock.h>
#include <linux/socket.h>

#include "sock.h"
#include "proto.h"

int register_cp_sock(void) {
    return sock_register(&cp_family_ops);
}

void unregister_cp_sock(void) {
    sock_unregister(CP_PROTOCOL_FAMILY);
}

int cp_create(struct net* net, struct socket *sock, int proto, int kern) {
    struct sock *sk;
    int rc;

    // If we are not allowed to create multiple instances of the network stack,
    // but are requested to do so, error out.
    rc = -ESOCKTNOSUPPORT;
    if (!net_eq(net, &init_net)) {
        rc = -EAFNOSUPPORT;
        goto out;
    }

    // Don't need to do anything more if they request a raw or connectionless
    // socket.
    if (sock->type != SOCK_RAW && sock->type != SOCK_DGRAM)
        goto out;

    // Are we capable of creating a raw socket, if requested?
    // If it's a kernel socket it is going to succeed.
    // TODO: wtf are kernel sockets?
    rc = -EPERM;
    if (!kern && sock->type == SOCK_RAW && !capable(CAP_NET_RAW))
        goto out;

    sk = sk_alloc(net, CP_PROTOCOL_FAMILY, GFP_KERNEL, &cp_proto, kern);
    if (!sk)
        goto out;

    out:
        return rc;
}
