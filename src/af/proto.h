#ifndef _CP_PROTO_H_
#define _CP_PROTO_H_

#include <net/sock.h>

#include "sock.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
static struct proto cp_proto = {
    .name       = "CP",
    .owner      = THIS_MODULE,
    .obj_size   = sizeof(struct cp_sock),
};
#pragma GCC diagnostic pop

int register_cp_proto(void);

#endif /* _CP_PROTO_H_ */
