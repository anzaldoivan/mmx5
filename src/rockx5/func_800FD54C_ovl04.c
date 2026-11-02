#include "types.h"

extern void func_8001296C(s32);
extern u8* func_8002D144(void);
extern s32 func_8002DF78(void);
extern s32 func_80031DD0(u8* a0);
extern void func_800FD484_ovl04(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_800755C0[];
extern u8 D_8009A1F8[];
extern s16 D_8009A206;
extern u8 D_800D1C00[];
extern u8* D_8010308C_ovl04;
extern u8* D_80103094_ovl04[];
extern u8 D_8010309C_ovl04[];

void func_800FD54C_ovl04(u8* arg0) {
    s32 r;
    s32 i;
    u8* p;
    u8* b;
    u8 t;

    if (D_800D1C00[0x2A] & 1) {
        r = func_80031DD0(arg0);
    } else {
        r = 0;
    }
    if (r < 0) {
        func_8001296C(0xA);
        D_800D1C00[0x2A] |= 4;
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
        arg0[5]++;
        D_800D1C00[0x24] = 0;
        for (i = 0; i < 2; i++) {
            p = D_80103094_ovl04[i];
            if (p != 0 && (s8)p[4] < 2) {
                p[4] = 5;
                D_80103094_ovl04[i] = 0;
                D_8010309C_ovl04[i] = 0x3C;
            }
        }
        D_8009A1F8[0x44] = 1;
        *(s16*)(arg0 + 0x7C) = 0;
        D_8010308C_ovl04 = func_8002D144();
        if (D_8010308C_ovl04 != 0) {
            *D_8010308C_ovl04 = 1;
            D_8010308C_ovl04[1] = 0xB;
        }
        return;
    }
    if (r > 0 && r != 0x7F) {
        arg0[0x8F] = (u32)(r - 0x19) < 2 ? 2 : 0x1E;
        *(u8**)(arg0 + 0x58) = D_80074EE0;
    }
    t = arg0[0x8F];
    if (t != 0) {
        arg0[0x8F] = t + 0xFF;
        if (t & 2) {
            *(u16*)(arg0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
        if (arg0[0x8F] == 0) {
            *(u8**)(arg0 + 0x58) = D_800755C0;
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
    }
    b = D_800D1C00;
    if (((s8*)b)[0x28] == 0) {
        if (arg0[0x8D] == 0 || --arg0[0x8D] == 0) {
            b[0x28] = 1 << (func_8002DF78() & 3);
            arg0[0x8D] = 0x3C;
        }
    }
    func_800FD484_ovl04(arg0);
    *(s16*)(arg0 + 0xE) = D_8009A206 + 0xB0;
}
