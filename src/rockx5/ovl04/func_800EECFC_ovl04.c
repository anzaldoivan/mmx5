#include "types.h"
#include "mmx5/globals.h"

extern u8* alloc_class3_slot(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C26;

void func_800EECFC_ovl04(u8* arg0) {
    u8* p;
    u8* q;
    u8* r;

    if (D_800D1C26 != 0) {
        func_8003D2C4();
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xE;
            p[2] = 0xC;
            r = g_Player;
            *(s32*)(p + 0x8) = *(s32*)(r + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(r + 0xC);
        }
        q = D_8009A1F8;
        q[0x44] = 0;
        *(s32*)(arg0 + 0x14) = *(s32*)(q + 0x8);
        *(s32*)(arg0 + 0x18) = *(s32*)(q + 0xC);
        *(s16*)(q + 0x26) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x24) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x1E) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x1C) = *(s16*)(arg0 + 0x16);
        *(s16*)(q + 0x2A) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x28) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x22) = *(s16*)(arg0 + 0x1A);
        *(s16*)(q + 0x20) = *(s16*)(arg0 + 0x1A);
        arg0[6]++;
    }
}
