obj-m := cdata.o
KVERSION := $(shell uname -r)

KDIR := /lib/modules/$(KVERSION)/build
PWD := $(shell pwd)

#$(info 	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules)
#$(info $(MAKE) $(DEBFLAGS) -C  /lib/modules/$(KVERSION)/build M=$(PWD) modules)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

load:
	sudo sh load.cdata.sh
unload:
	sudo sh unload.cdata.sh
clean:
	rm -rf *.o *.ko .*cmd modules.* Module.* .tmp_versions *.mod.c test

