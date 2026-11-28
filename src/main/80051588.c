#include "types.h"

void func_80051588(u8* p) {
    s32 x = *(s32*)(p + 0x14);
    s32 v = *(s32*)(p + 0x3C);
    x -= v;
    *(s32*)(p + 0x14) = x;
    *(s32*)(p + 0x2C) -= v;
    *(s32*)(p + 0x3C) = v + 0x8000;
    if (x < 0x300000) {
        p[5]++;
    }
}

void func_800515DC(u8* arg0) {
    arg0[5]++;
}

extern u8 D_80091C38[];

void func_800515F0(u8* arg0) {
    u8* p = D_80091C38;

    if (p[0xD] == 4 && *(s16*)(p + 0xA) < 0x1E) {
        *(s32*)(arg0 + 0x3C) = 0x40000;
        arg0[5]++;
    }
}

void func_80051634(u8* obj) {
    *(s32*)(obj + 0x1C) -= *(s32*)(obj + 0x3C);
    *(s32*)(obj + 0x24) -= *(s32*)(obj + 0x3C);
    *(s32*)(obj + 0x3C) += 0x8000;
    if (*(s32*)(obj + 0x1C) <= *(s32*)(obj + 0x14)) {
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0x14);
        obj[5] = 6;
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x2C);
    }
}

void func_80051688(u8* p) {
    *(s16*)(p + 0x16) += 8;
    *(s16*)(p + 0x1E) -= 8;
    *(s16*)(p + 0x26) -= 8;
    *(s16*)(p + 0x2E) += 8;
    if (*(s16*)(p + 0x16) >= *(s16*)(p + 0x1E)) {
        *(s16*)(p + 0x16) = *(s16*)(p + 0x1E);
        *(s16*)(p + 0x2E) = *(s16*)(p + 0x26);
        p[4]++;
    }
}
