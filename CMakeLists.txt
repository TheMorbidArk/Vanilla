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
	SOURCES entry.s main.c sbi.h .gitignore
	GENERATE_BIN
	GENERATE_MAP
	LINKER_SCRIPT link.ld)
