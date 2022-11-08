#include "proto.h"

#include <net/sock.h>

int register_cp_proto(void)
{
    return proto_register(&cp_proto, 1);
}

void unregister_cp_proto(void)
{
    proto_unregister(&cp_proto);
}
