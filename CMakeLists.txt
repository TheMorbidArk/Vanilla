cmake_minimum_required(VERSION 3.15)

project(Vanilla LANGUAGES C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_bsp(
	ID com.sysprogs.riscv.kendryte
	VERSION 1.0
	MCU K210
	DISABLE_GNU_EXTENSIONS
	HWREGISTER_LIST_FILE k210.mcudef)

add_bsp_based_executable(
	NAME Vanilla
	SOURCES
		.gitignore
		kernel/init/main.c
		kernel/init/entry.s
		kernel/sbi/sbi.c
		include/sbi/sbi.h
		include/defs.h
		include/driver/console.h
		include/mm/memlayout.h
		include/mm/mmu.h
		include/libs/error.h
		include/libs/riscv.h
		include/libs/r_stdarg.h
		include/libs/r_stdio.h
		include/libs/r_string.h
		kernel/driver/console.c
		kernel/libs/r_printfmt.c
		kernel/libs/r_readline.c
		kernel/libs/r_stdio.c
		kernel/libs/r_string.c
	GENERATE_BIN
	GENERATE_MAP
	LINKER_SCRIPT link.ld)
target_include_directories(Vanilla PRIVATE include include/sbi include/libs include/mm include/driver)
