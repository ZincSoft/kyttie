#ifndef _CP_IX_SOCK_H_
#define _CP_IX_SOCK_H_

#include <net/sock.h>
#include <linux/socket.h>
#include <cp.h>

/** Raw Catnet socket operations. */
int ix_release(struct socket *);
int ix_bind(struct socket *, struct sockaddr *, int);
int ix_connect(struct socket *, struct sockaddr *, int, int);
int ix_accept(struct socket *, struct socket *, int, _Bool);
int ix_getname(struct socket *, struct sockaddr *, int);
__poll_t ix_poll(struct file *, struct socket *, struct poll_table_struct *);
int ix_ioctl(struct socket *, unsigned int, long unsigned int);
int ix_listen(struct socket *, int);
int ix_shutdown(struct socket *, int);
int ix_setsockopt(struct socket *, int, int, sockptr_t, unsigned int);
int ix_getsockopt(struct socket *, int, int, char *, int *);
int ix_sendmsg(struct socket *, struct msghdr *, size_t);
int ix_recvmsg(struct socket *, struct msghdr *, size_t, int);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
/** Describe Catnet raw protocol family over IX. */
static const struct proto_ops ix_raw_ops = {
    .family = PF_CP,
    .owner = THIS_MODULE,

    .release    = ix_release,
    .bind       = ix_bind,
    .connect    = ix_connect,
    .accept     = ix_accept,
    .getname    = ix_getname,
    .poll       = ix_poll,
    .ioctl      = ix_ioctl,
    .listen     = ix_listen,
    .shutdown   = ix_shutdown,
    .setsockopt = ix_setsockopt,
    .getsockopt = ix_getsockopt,
    .sendmsg    = ix_sendmsg,
    .recvmsg    = ix_recvmsg,
};
#pragma GCC diagnostic pop

#endif /* _CP_IX_SOCK_H */
