#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/sched.h>
/*
 * cp_range(char *filename, void *start_addr, void* end_addr) write memory data to /checkpoint, from
 * start_addr to end_addr.
 */

asmlinkage int sys_cp_range(char *filename, void *start_addr, void * end_addr) {
  struct file *file;
  file = filp_open(filename, O_WRONLY|O_CREAT, 0644);
  if (file) {
    printk(KERN_DEBUG "File created successfully\n");
    printk(KERN_DEBUG "Pid: %d\n", current->pid);
    filp_close(file, NULL);
    printk(KERN_DEBUG "File closed successfully\n");
  }
  return 0;
}
