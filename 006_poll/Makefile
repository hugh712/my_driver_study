obj-m := cdata.o
KVERSION := $(shell uname -r)
DEVICE="cdata"
KDIR := /lib/modules/$(KVERSION)/build
PWD := $(shell pwd)


default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
test: 
	gcc -o main-loop main-loop.c
	gcc -o control control.c
load:
	sudo sh load.cdata.sh
unload:
	sudo sh unload.cdata.sh
clean:
	rm -rf *.o *.ko .*cmd modules.* Module.* .tmp_versions *.mod.c test main-loop control
show:
	ls -l /dev/$(DEVICE); lsmod | grep $(DEVICE)
