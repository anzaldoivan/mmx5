#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl50.h"
#include "mmx5/object.h"

extern u8 D_80091C44;

void func_800FA458_ovl50(u8* arg0) {
    u8* p;
    u8* q;

    if (D_80091C44 == 0) {
        p = alloc_class6_slot();
        D_800FBC88_ovl50 = p;
        if (p != 0) {
            p[0] = 1;
            D_800FBC88_ovl50[1] = 10;
            D_800FBC88_ovl50[0x36] = 0x22;
            D_800FBC88_ovl50[2] = 0;
        }
        q = D_8009A1F8.u;
        *(s32*)(q + 0x5C) = 0;
        *(s32*)(q + 0x60) = 0x800000;
        q[0xA0] = 1;
        q[0x57] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
