#include <linux/init.h>
#include <linux/module.h>
#include "add_sub.h"

int add_integer(int a, int b)
{
	return a+b;
}
int sub_integer(int a, int b)
{
	return a-b;
}

EXPORT_SYMBOL(add_integer);
EXPORT_SYMBOL(sub_integer);
MODULE_LICENSE("GPL");

