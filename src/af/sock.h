#ifndef _CP_SOCK_H_
#define _CP_SOCK_H_

#include <net/sock.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
static struct cp_sock {
    /* Sock has to be the first member or Linux stuff
     * will break ;) */
    struct sock sock;
} cp_sock;
#pragma GCC diagnostic pop

int register_cp_sock(void);

#endif /* _CP_SOCK_H_ */
