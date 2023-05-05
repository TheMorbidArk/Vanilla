
extern "C"
{
#include <sbi.h>
#include <r_stdio.h>
}

#include <r_iostream.hpp>

extern "C" void os_main()
{

    cprintf("Hello,RISC-V\n");
    
    eio::cout << "Hello,cout\n";
    
    while (1) {
        
    }
    
    return ;
}
