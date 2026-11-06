#include "types.h"

extern u32* D_800730AC[];
extern u8 D_8009A197;
extern u8 D_800D1C00[];
extern s32 D_800E9550;

void func_80046CAC(u8* arg0) {
    u8* obj;
    u8* dst;
    u32* p;
    s8 sel;
    s32 v;
    s32 cur;

    obj = *(u8**)(arg0 + 0x7C);
    dst = arg0 + 0x8C;
    if (*(s8*)(obj + 0x45) != 0) {
        if ((s8)D_800D1C00[0xC] == 0xC && (s8)D_800D1C00[0x1D] == 3) {
            arg0[4] = 4;
            arg0[5] = 0;
            return;
        }
        sel = arg0[1];
        if (sel == 2) {
            *dst = 8;
        } else if (sel == 0xB) {
            *dst = 0xA;
        } else {
            *dst = 9;
        }
        p = D_800730AC[(s8)D_800D1C00[0xC] * 2 + (s8)D_800D1C00[0xD]];
        D_800E9550 = 0;
        if (p != 0) {
            *p &= ~0x19FFFF;
        }
        D_8009A197 = 1;
        arg0[4]++;
    }
    v = *(s8*)(obj + 2);
    if (v == 0) {
        cur = *(s8*)(obj + 5);
        v = 0x26;
    } else {
        cur = *(s8*)(obj + 5);
        v = 0x3F;
    }
    if (cur != v) {
        arg0[4] = 3;
    }
}
