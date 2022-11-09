#include <net/sock.h>
#include <linux/socket.h>

#include "sock.h"
#include "ix/sock.h"
#include "proto.h"

int register_cp_sock(void)
{
    return sock_register(&cp_family_ops);
}

void unregister_cp_sock(void)
{
    sock_unregister(CP_PROTOCOL_FAMILY);
}

int cp_create(struct net* net, struct socket *sock, int proto, int kern)
{
    // NOTE: This needs to be refactored when the WAN exclusive
    // routing protocol is introduced! It's kinda weird as it
    // stands now.

    struct sock *sk;
    int rc;

    // If we are not allowed to create multiple instances of the network stack,
    // but are requested to do so, error out.
    rc = -EAFNOSUPPORT;
    if (!net_eq(net, &init_net))
        goto out;

    /* // Scream! (if the socket type isn't raw or dgram, we don't support other stuff)
    rc = -ESOCKTNOSUPPORT;
    if (sock->type != SOCK_RAW && sock->type != SOCK_DGRAM)
        goto out; */

    // Scream! (if the socket type isn't raw, we don't support other stuff)
    rc = -ESOCKTNOSUPPORT;
    if (sock->type != SOCK_RAW)
        goto out;

    // Are we capable of creating a raw socket, if requested?
    // If it's a kernel socket it is going to succeed.
    rc = -EPERM;
    if (!kern && sock->type == SOCK_RAW && !capable(CAP_NET_RAW))
        goto out;

    rc = -ENOMEM;
    sk = sk_alloc(net, CP_PROTOCOL_FAMILY, GFP_KERNEL, &cp_proto, kern);
    if (!sk)
        goto out;

    rc = 0;

    sock_init_data(sock, sk);

    sock->ops = &ix_raw_ops;
    sock->state = SS_UNCONNECTED;

    out:
        return rc;
}

