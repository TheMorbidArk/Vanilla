
extern "C"
{
#include <sbi.h>
#include <r_stdio.h>
    
void os_main();
}

void os_main()
{

    cprintf("Hello,RISC-V\n");
    
    while (1) {
        
    }
    
    return ;
}
