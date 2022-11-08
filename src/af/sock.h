#ifndef _CP_SOCK_H_
#define _CP_SOCK_H_

#include <net/sock.h>
#include <linux/socket.h>

#define CP_PROTOCOL_FAMILY PF_CP

/** Registers the Catnet socket functionality with the kernel.*/
int register_cp_sock(void);

/** Unregisters the Catnet socket functionality from the kernel. */
void unregister_cp_sock(void);

/** Create socket handler. */
int cp_create(struct net* net, struct socket *sock, int proto, int kern);

/** Raw Catnet socket operations. */
int cp_raw_release(struct socket *);
int cp_raw_bind(struct socket *, struct sockaddr *, int);
int cp_raw_connect(struct socket *, struct sockaddr *, int, int);
int cp_raw_accept(struct socket *, struct socket *, int, _Bool);
int cp_raw_getname(struct socket *, struct sockaddr *, int);
__poll_t cp_raw_poll(struct file *, struct socket *, struct poll_table_struct *);
int cp_raw_ioctl(struct socket *, unsigned int, long unsigned int);
int cp_raw_listen(struct socket *, int);
int cp_raw_shutdown(struct socket *, int);
int cp_raw_setsockopt(struct socket *, int, int, sockptr_t, unsigned int);
int cp_raw_getsockopt(struct socket *, int, int, char *, int *);
int cp_raw_sendmsg(struct socket *, struct msghdr *, size_t);
int cp_raw_recvmsg(struct socket *, struct msghdr *, size_t, int);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
/** Internal representation of a Catnet socket. */
static struct cp_sock {
    /* Sock has to be the first member or Linux stuff
     * will break ;) */
    struct sock sock;
} cp_sock;

/** Describe Catnet protocol family. */
static const struct net_proto_family cp_family_ops = {
    .family = CP_PROTOCOL_FAMILY,
    .create = cp_create,
    .owner  = THIS_MODULE,
};

/** Describe Catnet raw protocol family. */
static const struct proto_ops cp_raw_ops = {
    .family = CP_PROTOCOL_FAMILY,
    .owner = THIS_MODULE,

    .release    = cp_raw_release,
    .bind       = cp_raw_bind,
    .connect    = cp_raw_connect,
    .accept     = cp_raw_accept,
    .getname    = cp_raw_getname,
    .poll       = cp_raw_poll,
    .ioctl      = cp_raw_ioctl,
    .listen     = cp_raw_listen,
    .shutdown   = cp_raw_shutdown,
    .setsockopt = cp_raw_setsockopt,
    .getsockopt = cp_raw_getsockopt,
    .sendmsg    = cp_raw_sendmsg,
    .recvmsg    = cp_raw_recvmsg,
};
#pragma GCC diagnostic pop

#endif /* _CP_SOCK_H_ */
