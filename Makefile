
#obj-m += Module_Jiffies.o
#ccflags-y += -O0
#ccflags-y += -g

obj-m += Module_Jiffies.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean



