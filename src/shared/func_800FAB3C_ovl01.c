#include "types.h"
#include "mmx5/globals.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;
extern u8 D_800FDAB0_ovl01[];

void func_800FAB3C_ovl01(u8* arg0) {
    u8* p;
    u8* s;

    ((s32(*)())func_8003D29C)(0x14, 0x40);
    if (D_8009A0A5 != 0x14) {
        return;
    }
    p = D_8009A1F8.u;
    p[0x47] = 2;
    if (D_800D1C0C.s != 0xC) {
        func_80028B18(0, 0x25C0, 0xE0, D_800FDAB0_ovl01);
        p[0x4C] = 1;
    }
    s = alloc_class3_slot();
    if (s != 0) {
        s[0] = 1;
        s[1] = 0x18;
        *(u8**)(arg0 + 0x8C) = s;
    }
    ((s32(*)())func_8003D29C)(0x14, 0x40);
    *(s16*)(arg0 + 0x7C) = 0x168;
    arg0[6] = 1;
}
