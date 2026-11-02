#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8002D6FC(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern s32 D_800FE9F8_ovl06[];
extern s32 D_800FEA18_ovl06[];

void func_800F652C_ovl06(u8* arg0) {
    s32 n;
    s32 i;
    s32 x;
    u8* p;
    u8* o;

    n = 4;
    if (((s8*)arg0)[2] == 2) {
        n = 6;
    }
    if (((s8*)arg0)[2] >= 8) {
        p = D_8009A1F8;
        *(u16*)(p + 0x24) = *(u16*)(arg0 + 0x82);
        x = ((s8*)arg0)[2];
        n = 8;
        if (x == 8) {
            *(s16*)(p + 0x26) = 0x4F0;
        } else if (x == 9) {
            *(s16*)(p + 0x26) = 0x770;
        } else {
            *(s16*)(p + 0x26) = 0xA00;
        }
    }
    for (i = 0; i < n; i++) {
        o = func_8002D27C();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x21;
            o[0x15] = func_8002DF78() & 0x40;
            o[2] = arg0[2];
            *(s32*)(o + 8) =
                *(s32*)(arg0 + 8) + D_800FE9F8_ovl06[func_8002DF78() & 7];
            *(s32*)(o + 0xC) =
                *(s32*)(arg0 + 0xC) + D_800FEA18_ovl06[func_8002DF78() & 7];
            *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            o[0x14] = D_8009A0A0[0x14];
        }
        if (i & 1) {
            func_8004FD90(arg0, 1, 0xF, 0xF);
        }
    }
    func_8002D6FC(arg0);
}
