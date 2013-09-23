#include <linux/slab.h>
#include <linux/device.h>
#include "pointers.h"

void print_pointers(void)
{
	char *mem = kmalloc(1000, GFP_KERNEL);
	if (mem) {
		printk(KERN_INFO "allocated by kmalloc: %p\n", mem);
		kfree(mem);
	}
	printk(KERN_INFO "stack allocated: %p\n", &mem);
	printk(KERN_INFO "jiffies: %p\n", &jiffies);
	printk(KERN_INFO "function: %p\n", &bus_register);
	printk(KERN_INFO "__builtin_return_address(0): %pF\n",
		__builtin_return_address(0));
}
