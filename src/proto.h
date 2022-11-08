#ifndef _CP_PROTO_H_
#define _CP_PROTO_H_

#include <net/sock.h>

#include "sock.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
/** Protocol struct used for registration within the kernel. */
static struct proto cp_proto = {
    .name       = "CP",
    .owner      = THIS_MODULE,
    .obj_size   = sizeof(struct cp_sock),
};
#pragma GCC diagnostic pop

/** Registers the CP protocol family with the kernel. */
int register_cp_proto(void);

/** Unregisters the CP protocol family with the kernel. */
void unregister_cp_proto(void);

#endif /* _CP_PROTO_H_ */
