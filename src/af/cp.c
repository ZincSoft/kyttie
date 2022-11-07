/*
 * Main source file for the Kyttie module.
 */

#ifndef linux
#error "How the hell do you expect to build a Linux kernel module on a non-linux machine?"
#endif

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <net/sock.h>

#include "proto.h"
#include "sock.h"

MODULE_DESCRIPTION("Kyttie Catnet Implementation");
MODULE_AUTHOR("Milo Banks <(firstname)(lastname) @t rowland hall d0t org>");
MODULE_LICENSE("GPL");

static int __init kyt_init(void)
{
    int rc = 0;

    rc = register_cp_proto();
    if (rc != 0)
        goto err;
    rc = register_cp_sock();
    if (rc != 0)
        goto err;

err:
    return rc;
}

static void __exit kyt_exit(void)
{

}

module_init(kyt_init);
module_exit(kyt_exit);

