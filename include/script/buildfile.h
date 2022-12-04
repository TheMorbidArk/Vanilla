#ifndef BUILDFILE_H
#define BUILDFILE_H

#define BUILD_BOOT_OBJS
#define BUILD_HALY_OBJS init.o VanillaHalStart.o halInit.o \
                        platfrom.o vector.o interrupt.o
#define BUILD_KRNL_OBJS
#define BUILD_MEMY_OBJS
#define BUILD_FSYS_OBJS
#define BUILD_DRIV_OBJS
#define BUILD_LIBS_OBJS
#define BUILD_TASK_OBJS

#define BUILD_LINK_OBJS BUILD_BOOT_OBJS BUILD_HALY_OBJS\
                        BUILD_KRNL_OBJS BUILD_MEMY_OBJS\
                        BUILD_FSYS_OBJS BUILD_DRIV_OBJS\
                        BUILD_LIBS_OBJS BUILD_TASK_OBJS
#define LINKR_IPUT_FILE BUILD_LINK_OBJS
#define LINKR_OPUT_FILE Vanillamkrnl.elf
#define KERNL_ELFF_FILE LINKR_OPUT_FILE
#define KERNL_BINF_FILE Vanillamkrnl.bin
                          
#endif // BUILDFILE_H
