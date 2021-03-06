#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/vmalloc.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/miscdevice.h>
#include <linux/input.h>
#include <linux/platform_device.h>
#include <asm/io.h>
#include <asm/uaccess.h>

#include "cdata_ioctl.h"

#define CDATA_MAJOR 122
#define CDATA_MINOR 199
#define PTK(fmt,arg...) \
	  printk(KERN_INFO "[HELLO]:" fmt"\n", ## arg)

static int cdata_open(struct inode *inode, struct file * filp)
{
	PTK("cdata, hugh in open");

	return 0;
}

static int cdata_release(struct inode *inode, struct file * filp)
{
	PTK("cdata, hugh in rlease");

	return 0;
}

static long cdata_ioctl (struct file *filp, unsigned int cmd, unsigned long data)
{

	PTK("cdata, hugh in ioctl");


	switch(cmd)
	{


	  default:
		PTK("cdata: ioctl default");
		return -ENOTTY; 	

	}//end of switch

	return 0;
}

static struct file_operations cdata_fops= {
	owner:		THIS_MODULE,
	open :		cdata_open,
	unlocked_ioctl:	cdata_ioctl,
	release:	cdata_release,
};


static struct miscdevice cdata_misc = {
	minor:	CDATA_MINOR,
	name:	"cdata",
	fops:	&cdata_fops,
};

static int ldt_plat_probe(struct platform_device *pdev)
{
	if(misc_register(&cdata_misc) <0)
	{
		PTK("CDATA: can't register driver");
        	return -1;
	}
	return 0;
}

static int ldt_plat_remove(struct platform_device *pdev)
{
	misc_deregister(&cdata_misc);
	return 0;
}

static struct platform_driver ldt_plat_driver = {
	.driver = {
		   .name    = "cdata_dummy",
		   .owner   = THIS_MODULE
		  },
	.probe  =  ldt_plat_probe,
	.remove =  ldt_plat_remove,

};


int cdata_init_module(void)
{

	platform_driver_register(&ldt_plat_driver);
	PTK("cdata module: registered.");

    	return 0;
}

void  cdata_cleanup_module(void)
{


	platform_driver_unregister(&ldt_plat_driver);
  PTK("cdata module: unregisterd.");

}


module_init(cdata_init_module);
module_exit(cdata_cleanup_module);

MODULE_LICENSE("GPL");
