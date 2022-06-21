#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/proc_fs.h>
#include<asm/uaccess.h>

#define BUFFER_SIZE 128
#define PROC_NAME "hello"

ssize_t proc_read(struct file *file, char *usr_buf, size_t count, loff_t *pos);

static struct file_operations proc_ops = {
	.owner = THIS_MODULE,
	.read = proc_read,
};

/* This function is called when the module is loaded */
int proc_init(void) {
	/* creates the /proc/hello entry */
	proc_create(PROC_NAME, 0666, NULL, &proc_ops);

	return 0;
}

/* This function is called when the module is removed */
void proc_exit(void) {
	/* removes the /proc/hello entry */
	remove_proc_entry(PROC_NAME, NULL);
}

/* This function is called each time /proc/hello is read 
 * The string "Hello World\n" is written to the variable buffer which exists in kernel memory.
 * Contents of the kernel buffer are copied to the variable usr_buf which exists in user space using the kernel function raw_copy_to_user().
 * Each time /proc/hello is read, proc_read() function is called repeatedly until it returns 0
 */
ssize_t proc_read(struct file *file, char *usr_buf, size_t count, loff_t *pos) {
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;

	if(completed) {
		completed = 0;
		return 0;
	}

	completed = 1;

	rv = sprintf(buffer, "Hello World\n");

	/* copies kernel space buffer to user space usr_buf */
	raw_copy_to_user(usr_buf, buffer, rv);

	/* whatever value is returned by this function, that many number of characters from user buffer are printed */
	return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Module");
MODULE_AUTHOR("SGG");
