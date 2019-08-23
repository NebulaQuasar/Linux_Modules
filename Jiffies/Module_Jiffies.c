/*                                                     
 * Basic Module for Linux.
 * Jiffies Module. 
*/                                                    



#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <asm/param.h>

static unsigned long Jiffies_Count_Entry = 0;
static unsigned long Jiffies_Count_Exit  = 0;
static unsigned long Module_Time         = 0;

static int Module_Jiffies_init(void)

{

    dump_stack();                                       //very useful for diagnostics and debugging !!!
        
    printk(KERN_ALERT "Hello, System World \n");

    Jiffies_Count_Entry = jiffies;

    printk(KERN_ALERT "The Jiffies Count at Beginning %lu \n", Jiffies_Count_Entry);

    printk(KERN_ALERT "The time is %lu \n", (Jiffies_Count_Entry/HZ));

    return 0;                       //0 means, success !!! & Negative error code means failure !!!
                                    //if there is a failure notification, module will not be loaded and resources will be freed !!!
}


static void Module_Jiffies_exit(void)

{
    
    dump_stack();

    printk(KERN_ALERT "Goodbye, Cruel World \n");

    Jiffies_Count_Exit = jiffies;

    printk(KERN_ALERT "The Jiffies count at End %lu \n", Jiffies_Count_Entry);

    printk(KERN_ALERT "The time is %lu \n", (Jiffies_Count_Exit/HZ));

    Module_Time = ((Jiffies_Count_Exit/HZ)-(Jiffies_Count_Entry/HZ));

    printk(KERN_ALERT "The time for which Module was in Kernel is %lu Seconds \n", Module_Time);
}

module_init(Module_Jiffies_init);

module_exit(Module_Jiffies_exit);

//MODULE_LICENSE("Dual BSD/GPL");

MODULE_LICENSE("GPL");


















