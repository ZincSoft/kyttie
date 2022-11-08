#ifndef _CP_SOCK_H_
#define _CP_SOCK_H_

#include <net/sock.h>
#include <linux/socket.h>

#define CP_PROTOCOL_FAMILY PF_CP

int cp_create(struct net* net, struct socket *sock, int proto, int kern);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
static struct cp_sock {
    /* Sock has to be the first member or Linux stuff
     * will break ;) */
    struct sock sock;
} cp_sock;

static const struct net_proto_family cp_family_ops = {
    .family = CP_PROTOCOL_FAMILY,
    .create = cp_create,
    .owner  = THIS_MODULE,
};
#pragma GCC diagnostic pop

int register_cp_sock(void);
void unregister_cp_sock(void);
int cp_create(struct net* net, struct socket *sock, int proto, int kern);

#endif /* _CP_SOCK_H_ */
