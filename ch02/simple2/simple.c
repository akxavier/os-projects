#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<asm/param.h>		// for tick rate HZ
#include<linux/jiffies.h>

long int ins_time, rm_time;

int simple_init(void) {
	ins_time = jiffies/HZ;
	printk(KERN_INFO "Loading Module: Jiffies: %ld, HZ: %d\n", jiffies, HZ);
	return 0;
}

void simple_exit(void) {
	rm_time = jiffies/HZ;
	printk(KERN_INFO "Removing Module: Jiffies: %ld\n", jiffies);
	printk(KERN_INFO "Time between loading and unloading the module: %ld\n", (rm_time - ins_time));
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("MIT");
MODULE_AUTHOR("akxavier");
