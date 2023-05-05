#include "sbi.h"
void os_main()
{
    while (1) {
        SBI_PUTCHAR('H');
        SBI_PUTCHAR('e');
        SBI_PUTCHAR('l');
        SBI_PUTCHAR('l');
        SBI_PUTCHAR('o');
        SBI_PUTCHAR('\n');
    }
    return ;
}
