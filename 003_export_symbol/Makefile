
test:
	gcc -o test test.c
load:
	sudo sh load.cdata.sh
unload:
	sudo sh unload.cdata.sh
clean:
	rm -rf *.o *.ko .*cmd modules.* Module.* .tmp_versions *.mod.c test
show:
	ls -l /dev/$(DEVICE); lsmod | grep $(DEVICE)
