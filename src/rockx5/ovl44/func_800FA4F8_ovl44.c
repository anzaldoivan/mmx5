#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_80091C44;

void func_800FA4F8_ovl44(u8* arg0) {
    u8* q;
    u8* p;

    if (D_80091C44 == 0) {
        q = alloc_class6_slot();
        if (q != 0) {
            q[0] = 1;
            q[1] = 10;
            q[0x36] = 2;
            q[2] = 0;
        }
        p = D_8009A1F8.u;
        p[0x57] = 0;
        *(s32*)(p + 8) = 0x80000;
        *(s32*)(p + 0xC) = 0x800000;
        p[3] = 1;
        p[0x4C] = 1;
        arg0[1]++;
        *(s16*)(arg0 + 4) = 0;
    }
}
