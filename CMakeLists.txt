cmake_minimum_required(VERSION 3.15)

project(Vanilla LANGUAGES C CXX ASM)

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
	GENERATE_BIN
	GENERATE_MAP
	LINKER_SCRIPT link.ld)
target_include_directories(Vanilla PRIVATE include/sbi include)
