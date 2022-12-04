
#include "vanillaTypes.h"
#include "vanillaCtrl.h"

LKHEAD_T void initHal() {
    initPaltform();
    s3c2440vectorInit();
    while(1);
    return;
}