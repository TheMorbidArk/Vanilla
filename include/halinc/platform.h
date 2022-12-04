
//        平台相关的宏定义文件platform.h
#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "config.h"

void initPaltform();

//#ifdef CFG_S3C2440_PLATFORM

LKHEAD_T void s3c2440mmuInit();
LKHEAD_T void s3c2440mmuInvalidDicache();
LKHEAD_T void s3c2440mmuSetDomain(u32_t domain);
LKHEAD_T void s3c2440mmuSetTblbass(u32_t tblbphyadr);
LKHEAD_T void s3c2440mmuEnable();
LKHEAD_T void s3c2440vectorInit();
LKHEAD_T void s3c2440vectorCopy();
extern void vector();

//#endif

#endif // _PLATFORM_H
