/*
 * Main source file for the Kyttie module.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Kyttie Catnet Implementation");
MODULE_AUTHOR("Milo Banks <(firstname)(lastname) @t rowland hall d0t org>");
MODULE_LICENSE("GPL");

static int kyt_init(void)
{
        printk("MEOW!\n");
        return 0;
}

static void kyt_exit(void)
{
        printk("HISS!\n");
}

module_init(kyt_init);
module_exit(kyt_exit);

