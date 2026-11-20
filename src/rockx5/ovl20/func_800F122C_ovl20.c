#include "types.h"
#include "mmx5/object.h"

extern u8 D_800D1C00[];

void func_800F122C_ovl20(u8* arg0) {
    u8* base = D_800D1C00;
    u8* p;

    if (((s8*)base)[0x29] == 0) {
        p = alloc_class6_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xC;
            p[2] = 0x50;
        }
        base[0x29] = 1;
        arg0[2]++;
    }
}
