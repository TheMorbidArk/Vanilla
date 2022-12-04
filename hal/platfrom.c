
#include "vanillaTypes.h"
#include "vanillaCtrl.h"

void initPaltform() {
    s3c2440mmuInit();
    s3c2440vectorInit();
    return;
}

//#ifdef CFG_S3C2440_PLATFORM

LKHEAD_T void s3c2440mmuInit() {
    uint_t paddr = 0;
    u32_t pgdsc = 0;
    u32_t *pgdiradr = (u32_t *) PAGE_TLB_DIR;

    for (uint_t i = 0; i < PAGE_TLB_SIZE; i++) {
        pgdsc = (u32_t)(paddr |
                        PTE_SECT_AP | PTE_SECT_DOMAIN | PTE_SECT_BIT | PTE_SECT_NOCW);
        pgdiradr[i] = pgdsc;
        paddr += (0x100000);
    }
    pgdiradr[0] = SDRAM_MAPVECTPHY_ADDR |
                  PTE_SECT_NOCW | PTE_SECT_BIT | PTE_SECT_AP | PTE_SECT_DOMAIN;

    /** MMU 初始化
     * 1. 把页表的首地址写入CP15的C2中
     * 2. 设置域寄存器的所有位为1
     * 3. 使指令Cache和数据Cache中的数据无效
     * 4. 打开MMU
     */
    s3c2440mmuSetTblbass(PAGE_TLB_DIR);
    s3c2440mmuSetDomain(~0);
    s3c2440mmuInvalidDicache();
    s3c2440mmuEnable();

    return;
}

LKHEAD_T void s3c2440mmuInvalidDicache() {
    __asm__ __volatile__(
            "mov    r0, #0 \n\t"
            "mcr    p15, 0, r0, c7, c7, 0 \n\t"
            "mcr    p15, 0, r0, c7, c10, 4 \n\t"
            "mcr    p15, 0, r0, c8, c7, 0 \n\t"
            :
            :
            :"cc", "memory", "r0"
            );

    return;
}

LKHEAD_T void s3c2440mmuSetDomain(u32_t domain) {
    __asm__ __volatile__(
            "mcr p15,0,%[domval],c3,c0,0 \n\t"
            :
            : [domval]"r"(domain)
    : "cc", "memory"
    );
    return;
}

LKHEAD_T void s3c2440mmuSetTblbass(u32_t tblbphyadr) {

    __asm__ __volatile__ (
            "mcr p15,0,%[tbass],c2,c0,0 \n\t"
            :
            : [tbass]"r"(tblbphyadr)
    : "cc", "memory"
    );
    return;

}

LKHEAD_T void s3c2440mmuEnable() {
    __asm__ __volatile__(
            "mrc p15,0,r0,c1,c0,0 \n\t"
            "orr r0 ,#1 \n\t"
            "mcr p15,0,r0,c1,c0,0 \n\t"
            "nop \n\t"
            "nop \n\t"
            "nop \n\t"
            "nop \n\t"
            "nop \n\t"
            "nop \n\t"
            "nop \n\t"
            :
            :
            : "r0", "cc", "memory"
            );
    return;
}

LKHEAD_T void s3c2440vectorInit() {

}

//#endif