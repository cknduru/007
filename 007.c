#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Monitor packets");
MODULE_AUTHOR("cnduru");
MODULE_LICENSE("GPL");
 
int init_module()
{
        printk(KERN_INFO "module 007 is loaded into the kernel\n");
        return 0;
}
 
void cleanup_module()
{
        printk(KERN_INFO "module 007 has been unloaded\n");  
}
