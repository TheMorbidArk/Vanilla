MAKEFLAGS = -s
KERNELCE_PATH	= ../script/
HEADFILE_PATH = -I ../include/script/ -I ../include/ -I ../include/bastypeinc -I ../include/halinc
CCBUILDPATH	= $(KERNELCE_PATH)
# include krnlbuidcmd.mh
CC		= arm-linux-gcc
LD		= arm-linux-ld

DD		= dd 
LIBPATH		= -L /opt/armtoolschain/4.4.3/lib/gcc/arm-none-linux-gnueabi/4.4.3/libgcc.a -pipe -g -fno-common 
RM		= rm # -ld -lgcc  $(LIBPATH)
OBJCOPY		= arm-linux-objcopy
OYFLAGS		= -O binary
CFLAGS          = $(HEADFILE_PATH) -c -O2 -fno-builtin -ffreestanding -std=c99 -save-temps  -march=armv4 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion -fno-stack-protector -fomit-frame-pointer   -fno-ident  -Wno-unused-parameter -Wunused-variable -mtune=arm7tdmi
LDFLAGS		= -Bstatic -nostdlib -T lmemknllink.lds -Map lmos_em.map

CPPFLGSLDS	= $(HEADFILE_PATH) -E -P 


PREMENT_OBJS = krnlobjs.mkh lmemknllink.lds
.PHONY : all everything  build_kernel
all: build_kernel

build_kernel:everything

everything : $(PREMENT_OBJS)
#include krnlbuidrule.mh

CCSTR		= 	'CC -[M] 正在构建... '$<
PRINTCSTR 	=	@echo $(CCSTR) 

%.krnl : $(CCBUILDPATH)%.c
	$(CC) $(CFLAGS) -o $@ $<
	$(PRINTCSTR)
%.krnl : $(CCBUILDPATH)%.S
	$(CC) $(CFLAGS) -o $@ $<
	$(PRINTCSTR)
%.o : $(CCBUILDPATH)%.c
	$(CC) $(CFLAGS) -o $@ $<
	$(PRINTCSTR)
%.o : $(CCBUILDPATH)%.S
	$(CC) $(CFLAGS) -o $@ $<
	$(PRINTCSTR)	
%.lds : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $@ $<
	$(PRINTCSTR)

%.mkh : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $@ $<
	$(PRINTCSTR)