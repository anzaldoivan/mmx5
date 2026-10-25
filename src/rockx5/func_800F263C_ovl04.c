#include "types.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_8009A0A0[];
extern u8 D_80101640_ovl04[];

void func_800F263C_ovl04(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[0x45] == 1) {
        p = D_8009A0A0;
        p[0xCA] = 0;
        if (p[0x5C] & 0x7F) {
            p[3] = 1;
        }
        func_8004D4F4(5, D_80101640_ovl04, arg0);
    } else if (((s8*)arg0)[0x45] == 2) {
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0xF;
        *(s16*)(arg0 + 0x7E) = 5;
        arg0[4] = 6;
    }
}
