#include "types.h"
#include "mmx5/ovl01.h"

extern u8* alloc_class3_slot(void);

void func_800F6F28_ovl01(s32 arg0, u8 arg1) {
    u8* p = alloc_class3_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 9;
        *(u16*)(p + 0xA) = D_800FCFF0_ovl01.r[arg1][2];
        *(u16*)(p + 0xE) = D_800FCFF0_ovl01.r[arg1][3];
        p[2] = *(u8*)D_800FCFF0_ovl01.r[arg1];
        *(s32*)(p + 0x20) = arg0;
    }
}
