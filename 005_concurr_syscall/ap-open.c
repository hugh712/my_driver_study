#include <linux/unistd.h>
#include <stdio.h>
#include <stdlib.h>

int CustomEvent_open(int flag){
	return syscall(__NR_CustomEvent_open,flag);
}

int main(int argc, char ** argv)
{
	int i;
	if(argc !=2)
		return -1;

	i=CustomEvent_open(atoi(argv[1]));
	printf("%d\n", i)
	return 0;
}
