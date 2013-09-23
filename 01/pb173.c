#include <linux/module.h>
#include <linux/slab.h>
#include "pointers.h"

static int my_init(void)
{
	printk(KERN_INFO "Hello world\n");
	print_pointers();
	return 0;
}

static void my_exit(void)
{
	char *mem = kmalloc(1000, GFP_KERNEL);
	if (mem) {
		strcpy(mem, "Bye");
		printk(KERN_INFO "%s\n", mem);
		kfree(mem);
	}
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
