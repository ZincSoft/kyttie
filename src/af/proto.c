#include "proto.h"

#include <net/sock.h>

int register_cp_proto(void) {
    return proto_register(&cp_proto, 1);
}
