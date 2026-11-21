#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_800D1C2A;
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DF6_ovl20;
extern u8 D_800F6DF7_ovl20;

void func_800F111C_ovl20(u8* arg0) {
    u8 v = D_800F6DF7_ovl20;

    D_800F6DF6_ovl20 = v;
    D_800D1C2A = D_800F6DF0_ovl20[(s8)v];
    arg0[2]++;
}

extern u8 D_8009A1F8[];

void func_800F1160_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u8* p;

    b = D_8009A1F8;
    if (*(s16*)(b + 0x5E) < 0x281) {
        *(s16*)(b + 0x5E) -= 8;
    } else {
        *(s16*)(b + 0x5E) += 8;
    }
    c = D_8009A1F8;
    if ((u16)(*(u16*)(c + 0x5E) - 0x141) >= 0x3BF) {
        *(s16*)(c + 0x5E) = 0x140;
        c[0xA0] = 1;
        arg0[2]++;
        p = alloc_class6_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xC;
            p[2] = 0x50;
        }
        D_800D1C28[1] = 1;
    }
}

void func_800F1200_ovl20(u8* arg0) {
    if (D_800D1C28[1] == 0) {
        arg0[2]++;
    }
}

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

void func_800F12A8_ovl20(u8* arg0) {
    if (D_800D1C28[1] == 0) {
        arg0[1] = 6;
        arg0[2] = 0;
    }
}

#define D_800F5024_ovl24 D_800F51D8_ovl20

#define func_800EFFBC_ovl24 func_800F12CC_ovl20
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

#define D_800F5024_ovl24 D_800F5298_ovl20

#define func_800EFFBC_ovl24 func_800F1308_ovl20
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

extern u8 D_8009A1F8[];

void func_800F1344_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u8* e;
    s16 d;

    b = D_8009A1F8;
    if (*(s16*)(b + 0x5E) < 0x281) {
        *(s16*)(b + 0x5E) += 8;
    } else {
        *(s16*)(b + 0x5E) -= 8;
    }
    c = D_8009A1F8;
    d = (*(s16*)(c + 0x5E) - 0x280) < 0 ? (0x280 - *(s16*)(c + 0x5E))
                                        : (*(s16*)(c + 0x5E) - 0x280);
    if (d < 8) {
        e = D_8009A1F8;
        *(s16*)(e + 0x5E) = 0x280;
        arg0[1] = 4;
        arg0[2] = 0;
    }
}
