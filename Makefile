KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m = scull.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
