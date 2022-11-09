#include <net/sock.h>
#include <linux/socket.h>

#include "sock.h"

int ix_release(struct socket *)
{
    pr_err("ix_release: unimplemented");
    return 0;
}

int ix_bind(struct socket *, struct sockaddr *, int)
{
    pr_err("ix_bind: unimplemented");
    return 0;
}

int ix_connect(struct socket *, struct sockaddr *, int, int)
{
    pr_err("ix_connect: unimplemented");
    return 0;
}

int ix_accept(struct socket *, struct socket *, int, _Bool)
{
    pr_err("ix_accept: unimplemented");
    return 0;
}

int ix_getname(struct socket *, struct sockaddr *, int)
{
    pr_err("ix_getname: unimplemented");
    return 0;
}

__poll_t ix_poll(struct file *, struct socket *, struct poll_table_struct *)
{
    pr_err("ix_poll: unimplemented");
    return 0;
}

int ix_ioctl(struct socket *, unsigned int, long unsigned int)
{
    pr_err("ix_ioctl: unimplemented");
    return 0;
}

int ix_listen(struct socket *, int)
{
    pr_err("ix_error: unimplemented");
    return 0;
}

int ix_shutdown(struct socket *, int)
{
    pr_err("ix_shutdown: unimplemented");
    return 0;
}

int ix_setsockopt(struct socket *, int, int, sockptr_t, unsigned int)
{
    pr_err("ix_setsockopt: unimplemented");
    return 0;
}

int ix_getsockopt(struct socket *, int, int, char *, int *)
{
    pr_err("ix_getsockopt: unimplemented");
    return 0;
}

int ix_sendmsg(struct socket *, struct msghdr *, size_t)
{
    pr_err("ix_sendmsg: unimplemented");
    return 0;
}

int ix_recvmsg(struct socket *, struct msghdr *, size_t, int)
{
    pr_err("ix_recvmsg: unimplemented");
    return 0;
}

