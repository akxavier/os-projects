#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/hash.h>		// for GOLDEN_RATIO_PRIME
#include<linux/gcd.h>

/* This function is called on loading the module */
int simple_init(void) {
	printk(KERN_INFO "Loading Kernel Module\n");
	printk(KERN_INFO "%llu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "GCD of 3300 and 24 is: %lu\n", gcd(3300, 24));
	return 0;
}

/* This function is called on unloading the module */
void simple_exit(void) {
	printk(KERN_INFO "Removing Kernel Module\n");
}

/* Macros for registering module entry and exit points */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("AKX");
